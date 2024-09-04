#!/bin/bash

# Define colors
RED="\033[0;31m"
GREEN="\033[0;32m"
YELLOW="\033[0;33m"
BLUE="\033[0;34m"
PURPLE="\033[0;35m"
CYAN="\033[0;36m"
WHITE="\033[0m" # No color

# Function to print messages with "=>" prefix
print_with_arrow() {
    local message=$1
    local color=$2
    echo -e "=>${color} ${message}${NC}"
}

# Clean up .cmi and .cmo files from predefined list
clean_up() {
    print_with_arrow "Cleaning up predefined files..." "$YELLOW"

    # Add your predefined list of files to delete here
    FILES_TO_DELETE=(
        "Ispeak.cmi"
        "Ispeak.cmo"
        "translator.cmi"
        "translator.cmo"
        # Add other files if needed
    )

    for file in "${FILES_TO_DELETE[@]}"; do
        if [ -f "$file" ]; then
            rm "$file"
            print_with_arrow "Deleted $file" "$GREEN"
        else
            print_with_arrow "$file not found, skipping..." "$RED"
        fi
    done

    print_with_arrow "Cleanup complete." "$GREEN"
}

# Main process
if [ "$1" == "clean" ]; then
    clean_up
    exit 0
fi

# Get current directory
CURRENT_DIR=$(pwd)
print_with_arrow "Current directory: $CURRENT_DIR" "$BLUE"

# Navigate up two directories
cd ../..
print_with_arrow "Moved up two directories: $(pwd)" "$BLUE"

# Compile the files one by one
print_with_arrow "Compiling individual files..." "$GREEN"

# Step 1: Compile translator.ml
ocamlc -c -I +str -I compiler/colorizer -I compiler/lang compiler/lang/translator.ml
if [ $? -ne 0 ]; then
    print_with_arrow "Failed to compile translator.ml" "$RED"
    exit 1
fi

# Step 2: Compile Ispeak.ml with final command
ocamlc -o build/Ispeak -I +str -I compiler/colorizer -I compiler/lang \
str.cma \
compiler/colorizer/colorizer.cmo \
compiler/lang/translator.cmo \
compiler/lang/Ispeak.ml
if [ $? -eq 0 ]; then
    print_with_arrow "Compilation successful. Executable 'Ispeak' created." "$GREEN"
else
    print_with_arrow "Compilation failed." "$RED"
    exit 1
fi

# Return to the original directory
cd "$CURRENT_DIR"
print_with_arrow "Returned to original directory: $CURRENT_DIR" "$BLUE"
