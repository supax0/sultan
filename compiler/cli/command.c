#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <pwd.h>
#include <signal.h>
#include <sys/wait.h>  // For waitpid
#include <time.h>      // For nanosleep

#define PID_FILE_PATH "/tmp/sultanc_server.pid"  // Path to store the PID of the running server

// Structure to hold server information
struct ServerInfo {
    pid_t pid;
    int port;
};

// Global server instance
struct ServerInfo current_server = {0, 5140};  // Assume default port 5140

// Function to get the home directory
void get_home_directory(char *buffer, size_t size) {
    const char *homedir;

    if ((homedir = getenv("HOME")) == NULL) {
        homedir = getpwuid(getuid())->pw_dir;
    }

    strncpy(buffer, homedir, size);
}

// Function to get the current working directory
void get_current_directory(char *buffer, size_t size) {
    if (getcwd(buffer, size) == NULL) {
        fprintf(stderr, "Error: Failed to get current directory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
}

// Function to read the PID from the PID file
pid_t read_pid_from_file() {
    FILE *pid_file = fopen(PID_FILE_PATH, "r");
    if (pid_file == NULL) {
        return 0;  // PID file doesn't exist, so no server is running
    }

    pid_t pid;
    fscanf(pid_file, "%d", &pid);
    fclose(pid_file);
    return pid;
}

// Function to write the PID to the PID file
void write_pid_to_file(pid_t pid) {
    FILE *pid_file = fopen(PID_FILE_PATH, "w");
    if (pid_file == NULL) {
        fprintf(stderr, "Error: Could not create PID file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    fprintf(pid_file, "%d", pid);
    fclose(pid_file);
}

// Function to remove the PID file
void remove_pid_file() {
    if (remove(PID_FILE_PATH) != 0) {
        fprintf(stderr, "Error: Could not remove PID file: %s\n", strerror(errno));
    }
}

// Function to check if a server is already running by reading the PID file
int is_server_running() {
    pid_t pid = read_pid_from_file();
    if (pid > 0) {
        // Check if the process is still running
        if (kill(pid, 0) == 0) {
            return 1;  // Process is still running
        } else {
            remove_pid_file();  // The process is not running, clean up
        }
    }
    return 0;  // No server is running
}

// Function to start the server, retrying if the port is still in use
void start_server(int port) {
    int retries = 5;  // Number of retries if the port is in use
    struct timespec delay = {0, 500000000};  // 0.5 seconds

    while (retries > 0) {
        if (is_server_running()) {
            printf("Error: A server is already running on port %d with PID %d. Use 'realive' to restart or 'stop' to stop it.\n", current_server.port, read_pid_from_file());
            return;
        }

        char home_dir[PATH_MAX];
        char current_dir[PATH_MAX];
        char port_str[6];  // Ensure size is large enough for port strings like "5140"
        snprintf(port_str, sizeof(port_str), "%d", port);

        get_home_directory(home_dir, sizeof(home_dir));
        get_current_directory(current_dir, sizeof(current_dir));

        char server_path[PATH_MAX];
        snprintf(server_path, sizeof(server_path), "%s/.supax/lde/server.py", home_dir);

        pid_t pid = fork();
        if (pid == 0) {
            // Child process: start the server and pass the port and directory in the correct order
            execlp("python3", "python3", server_path, port_str, current_dir, (char *)NULL);
            fprintf(stderr, "Failed to start server: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        } else if (pid > 0) {
            // Parent process: save the PID to file
            current_server.pid = pid;
            current_server.port = port;
            write_pid_to_file(pid);
            printf("Server started on port %d with PID %d.\n", port, pid);
            return;
        } else {
            fprintf(stderr, "Error: Failed to fork process: %s\n", strerror(errno));
            return;
        }

        // Retry if the port is still in use
        printf("Retrying to start server on port %d...\n", port);
        nanosleep(&delay, NULL);  // Wait before retrying
        retries--;
    }

    fprintf(stderr, "Error: Failed to start server after multiple attempts. Port %d may still be in use.\n", port);
}

// Function to stop the server by reading the PID file and killing the process
void stop_server() {
    pid_t pid = read_pid_from_file();
    if (pid > 0) {
        // Wait for the process to terminate
        if (kill(pid, SIGTERM) == 0) {
            waitpid(pid, NULL, 0);  // Wait for the process to fully terminate
            printf("Server with PID %d stopped successfully.\n", pid);
            remove_pid_file();
        } else {
            fprintf(stderr, "Error: Failed to stop server with PID %d: %s\n", pid, strerror(errno));
        }
    } else {
        printf("No server is currently running.\n");
    }
}

// Function to restart the server (stop and start again)
void restart_server(int port) {
    if (is_server_running()) {
        printf("Restarting server on port %d...\n", port);
        stop_server();
    }
    start_server(port);
}

// Function to handle "alive", "stop", and "realive" commands
int handle_commands(const char *command) {
    if (strcmp(command, "alive") == 0) {
        start_server(current_server.port);
        return 0;
    } else if (strcmp(command, "stop") == 0) {
        stop_server();
        return 0;
    } else if (strcmp(command, "realive") == 0) {
        restart_server(current_server.port);
        return 0;
    }
    return -1;  // Invalid command
}
