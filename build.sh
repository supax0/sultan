#!/bin/bash

# Function for Step 1: Compile almostashar.mli
step_compile_almostashar_mli() {
    echo "Compiling almostashar.mli"
    ocamlc -I compiler/lexer -c compiler/lexer/almostashar.mli
}

# Function for Step 2: Compile almostashar.ml
step_compile_almostashar_ml() {
    echo "Compiling almostashar.ml"
    ocamlc -I compiler/lexer -c compiler/lexer/almostashar.ml
}

# Function for Step 3: Compile ast.mli
step_compile_ast_mli() {
    echo "Compiling ast.mli"
    ocamlc -I compiler/lexer -c compiler/lexer/ast.mli
}

# Function for Step 4: Compile ast.ml
step_compile_ast_ml() {
    echo "Compiling ast.ml"
    ocamlc -I compiler/lexer -c compiler/lexer/ast.ml
}

# Function for Step 5: Run ocamlyacc on parser.mly
step_ocamlyacc_parser_mly() {
    echo "Running ocamlyacc on parser.mly"
    ocamlyacc compiler/lexer/parser.mly
}

# Function for Step 6: Compile parser.mli
step_compile_parser_mli() {
    echo "Compiling parser.mli"
    ocamlc -I compiler/lexer -c compiler/lexer/parser.mli
}

# Function for Step 7: Compile parser.ml
step_compile_parser_ml() {
    echo "Compiling parser.ml"
    ocamlc -I compiler/lexer -c compiler/lexer/parser.ml
}

# Function for Step 8: Run ocamllex on lexer.mll
step_ocamllex_lexer_mll() {
    echo "Running ocamllex on lexer.mll"
    ocamllex compiler/lexer/lexer.mll
}

# Function for Step 9: Compile lexer.ml
step_compile_lexer_ml() {
    echo "Compiling lexer.ml"
    ocamlc -I compiler/lexer -c compiler/lexer/lexer.ml
}

# Function for additional compilation steps
step_compile_additional() {
    echo "Compiling additional modules"
    ocamlc -c -I wazir -I compiler/colorizer -I compiler/lang -I +str wazir/utils.ml
    ocamlc -c -I wazir -I compiler/colorizer -I compiler/lang -I +str compiler/colorizer/colorizer.ml
    ocamlc -c -I wazir -I compiler/colorizer -I compiler/lang -I +str compiler/lang/translator.ml
    ocamlc -c -I wazir -I compiler/colorizer -I compiler/lang -I +str wazir/loader.mli
    ocamlc -c -I wazir -I compiler/colorizer -I compiler/lang -I +str wazir/loader.ml
    ocamlc -c -I wazir -I compiler/colorizer -I compiler/lang -I +str wazir/command_parser.mli
    ocamlc -c -I wazir -I compiler/colorizer -I compiler/lang -I +str wazir/command_parser.ml
    ocamlc -c -I wazir -I compiler/colorizer -I compiler/lang -I compiler/lexer -I +str wazir/wazir.ml
}

# Function for linking the final executable
step_link_program() {
    echo "Linking the final executable"
    ocamlc -o sultanc \
        -I +str str.cma \
        compiler/lexer/almostashar.cmo \
        compiler/lexer/ast.cmo \
        library/core/stdlib/Int/int.cmo \
        library/core/stdlib/Bool/bool.cmo \
        library/core/stdlib/Var/var.cmo \
        library/core/stdlib/BinOp/binop.cmo \
        library/core/stdlib/UnOp/unop.cmo \
        library/core/stdlib/FunctionCall/functioncall.cmo \
        library/core/stdlib/Assign/assign.cmo \
        library/core/stdlib/ArrayLiteral/arrayliteral.cmo \
        library/core/stdlib/FunctionDef/functiondef.cmo \
        library/core/stdlib/ClassDef/classdef.cmo \
        library/core/stdlib/If/if.cmo \
        library/core/stdlib/Else/else.cmo \
        library/core/stdlib/ElseIf/elseif.cmo \
        library/core/stdlib/While/while.cmo \
        library/core/stdlib/For/for.cmo \
        library/core/stdlib/Return/return.cmo \
        library/core/stdlib/Import/import.cmo \
        library/core/stdlib/As/as.cmo \
        library/core/stdlib/From/from.cmo \
        library/core/stdlib/Pass/pass.cmo \
        library/core/stdlib/Break/break.cmo \
        library/core/stdlib/Continue/continue.cmo \
        library/core/stdlib/Read/read.cmo \
        library/core/stdlib/Write/write.cmo \
        compiler/lexer/parser.cmo \
        compiler/lexer/lexer.cmo \
        compiler/colorizer/colorizer.cmo \
        compiler/lang/translator.cmo \
        wazir/utils.cmo \
        wazir/loader.cmo \
        wazir/command_parser.cmo \
        wazir/wazir.cmo
}

# Target the step provided as an argument, or run all steps if no argument is provided
if [ -z "$1" ]; then
    step_compile_almostashar_mli
    step_compile_almostashar_ml
    step_compile_ast_mli
    step_compile_ast_ml
    step_ocamlyacc_parser_mly
    step_compile_parser_mli
    step_compile_parser_ml
    step_ocamllex_lexer_mll
    step_compile_lexer_ml
    step_compile_additional
    step_link_program
else
    "$1"
fi
