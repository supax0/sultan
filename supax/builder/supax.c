#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#ifdef _WIN32
#include <direct.h>  // Windows directory creation
#include <windows.h> // Windows process execution
#else
#include <unistd.h>  // Unix directory functions
#endif

void create_directory(const char *path) {
#ifdef _WIN32
    if (_mkdir(path) == 0) {
#else
    if (mkdir(path, 0755) == 0) {
#endif
        printf("Directory created: %s\n", path);
    } else {
        printf("Directory already exists or failed to create: %s\n", path);
    }
}

void copy_files(const char *src, const char *dest) {
    char command[512];

#ifdef _WIN32
    // Using xcopy for Windows
    snprintf(command, sizeof(command), "xcopy /E /I /Y \"%s\" \"%s\"", src, dest);
#else
    // Using cp for Linux/Mac
    snprintf(command, sizeof(command), "cp -r \"%s\" \"%s\"", src, dest);
#endif

    printf("Copying files from %s to %s\n", src, dest);
    system(command);
}

void run_installer(const char *installer_path) {
#ifdef _WIN32
    // Windows: run installer using ShellExecute
    ShellExecute(0, "open", installer_path, NULL, NULL, SW_SHOWNORMAL);
#else
    // Linux/Mac: run installer using system call
    char command[512];
    snprintf(command, sizeof(command), "sh %s", installer_path);
    printf("Running installer: %s\n", command);
    system(command);
#endif
}

int main() {
    const char *home;
    const char *supax_folder = "/.supax";
    char supax_home[512];

#ifdef _WIN32
    home = getenv("USERPROFILE");  // Windows home directory
#else
    home = getenv("HOME");         // Linux/Mac home directory
#endif

    if (!home) {
        printf("Failed to get home directory.\n");
        return 1;
    }

    // Step 1: Create the .supax directory in the home folder
    snprintf(supax_home, sizeof(supax_home), "%s%s", home, supax_folder);
    create_directory(supax_home);

    // Step 2: Copy files and folders to the new .supax directory
    copy_files("../lde", supax_home);

    // Step 3: Run the installer script
    run_installer("../sultanc-installer/installer.sh");

    return 0;
}
