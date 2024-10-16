#!/bin/sh

# Directories
BIN_DIR="../bin"
BIN_NAME="supax"
BUILD_DIR="supax/builder"

# Detect Clang or fallback to GCC
detect_compiler() {
    if command -v clang >/dev/null 2>&1; then
        echo "clang"
    elif command -v gcc >/dev/null 2>&1; then
        echo "gcc"
    else
        echo "none"
    fi
}

# Detect the available compiler
compiler=$(detect_compiler)

# Exit if no suitable compiler is found
if [ "$compiler" = "none" ]; then
    echo "Error: No suitable compiler found. Please install Clang or GCC."
    exit 1
fi

# Change to the supax/builder directory
cd "$BUILD_DIR" || { echo "Error: Failed to change directory to $BUILD_DIR"; exit 1; }

# Create the bin directory if it doesn't exist
if [ ! -d "$BIN_DIR" ]; then
    echo "Creating bin directory..."
    mkdir -p "$BIN_DIR"
fi

# Compile supax.c to the bin directory
echo "Using $compiler to compile Supax..."
$compiler -o "$BIN_DIR/$BIN_NAME" "supax.c"

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. The binary is located at '$BIN_DIR/$BIN_NAME'."
else
    echo "Error: Compilation failed."
    exit 1
fi

# Exit the script and run the binary in the foreground
# echo "Exiting script and running the Supax binary..."
"$BIN_DIR/$BIN_NAME"
exit 0
