#!/bin/bash

# Function to confirm and clean almostashar files
clean_almostashar() {
    read -p "Are you sure you want to clean almostashar files? (y/n) " confirm
    if [ "$confirm" = "y" ]; then
        echo "Cleaning almostashar files"
        rm -f compiler/lexer/almostashar.cmi compiler/lexer/almostashar.cmo
    else
        echo "Skipping almostashar files clean-up"
    fi
}

# Function to confirm and clean ast files
clean_ast() {
    read -p "Are you sure you want to clean ast files? (y/n) " confirm
    if [ "$confirm" = "y" ]; then
        echo "Cleaning ast files"
        rm -f compiler/lexer/ast.cmi compiler/lexer/ast.cmo
    else
        echo "Skipping ast files clean-up"
    fi
}

# Function to confirm and clean parser files
clean_parser() {
    read -p "Are you sure you want to clean parser files? (y/n) " confirm
    if [ "$confirm" = "y" ]; then
        echo "Cleaning parser files"
        rm -f compiler/lexer/parser.cmi compiler/lexer/parser.cmo parser.output
    else
        echo "Skipping parser files clean-up"
    fi
}

# Function to confirm and clean lexer files
clean_lexer() {
    read -p "Are you sure you want to clean lexer files? (y/n) " confirm
    if [ "$confirm" = "y" ]; then
        echo "Cleaning lexer files"
        rm -f compiler/lexer/lexer.cmi compiler/lexer/lexer.cmo compiler/lexer/lexer.ml
    else
        echo "Skipping lexer files clean-up"
    fi
}

# Function to confirm and clean additional compiled files
clean_additional() {
    read -p "Are you sure you want to clean additional compiled files? (y/n) " confirm
    if [ "$confirm" = "y" ]; then
        echo "Cleaning additional compiled files"
        rm -f wazir/utils.cmi wazir/utils.cmo
        rm -f compiler/colorizer/colorizer.cmi compiler/colorizer/colorizer.cmo
        rm -f compiler/lang/translator.cmi compiler/lang/translator.cmo
        rm -f wazir/loader.cmi wazir/loader.cmo
        rm -f wazir/command_parser.cmi wazir/command_parser.cmo
        rm -f wazir/wazir.cmi wazir/wazir.cmo
    else
        echo "Skipping additional compiled files clean-up"
    fi
}

# Function to confirm and clean the final executable
clean_program() {
    read -p "Are you sure you want to clean the final executable? (y/n) " confirm
    if [ "$confirm" = "y" ]; then
        echo "Cleaning the final executable"
        rm -f my_program
    else
        echo "Skipping final executable clean-up"
    fi
}

# Target the clean step provided as an argument, or run all clean steps if no argument is provided
if [ -z "$1" ]; then
    clean_almostashar
    clean_ast
    clean_parser
    clean_lexer
    clean_additional
    clean_program
else
    "$1"
fi
