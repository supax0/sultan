#!/bin/bash
echo "=> Starting to compile the sutlanc compiler"
# Get the directory where this script is located
SCRIPT_DIR=$(dirname "$0")

# Change to the source directory (assuming 'compiler' is a subdirectory of where the script is)
cd "$SCRIPT_DIR/../../compiler" || { echo "Could not change directory to compiler"; exit 1; }

# Check if clang or gcc is available
if command -v clang > /dev/null 2>&1; then
    COMPILER="clang"
elif command -v gcc > /dev/null 2>&1; then
    COMPILER="gcc"
else
    echo "Neither clang nor gcc is installed. Please install a compiler."
    exit 1
fi

# Set the source files and output file
SOURCE_FILES="interface/main.c builder/driver.c parser/sultanc.c lexer/lex.c \
cli/command.c  utils/helpers.c utils/error_handling.c utils/parser_helpers.c"

OUTPUT_FILE="bin/sultanc"  # The output is placed in the 'bin' folder, relative to 'compiler'

# Compile using the detected compiler
$COMPILER $SOURCE_FILES -o $OUTPUT_FILE

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Binary created at $OUTPUT_FILE"
    
    # Create a symlink to /usr/local/bin so it can be accessed system-wide
    if [ -f /usr/local/bin/sultanc ]; then
        sudo rm /usr/local/bin/sultanc  # Remove old symlink if it exists
    fi

    sudo ln -s "$(pwd)/$OUTPUT_FILE" /usr/local/bin/sultanc

    # Check if symlink creation was successful
    if [ $? -eq 0 ]; then
        echo "'sultanc' is now symlinked and accessible system-wide."
    else
        echo "Failed to create symlink in /usr/local/bin. Check permissions."
        exit 1
    fi
else
    echo "Could not compile the project."
    exit 1
fi
