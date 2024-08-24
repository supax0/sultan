# Makefile for compiling OCaml lexer, parser, and AST module with proper dependencies

OCAMLLEX=ocamllex
OCAMLYACC=ocamlyacc
OCAMLC=ocamlc

all: lexer.cmo parser.cmo

# Compile the Ast module first
ast.cmo: ast.ml
	$(OCAMLC) -c ast.ml

parser.mli: parser.mly
	$(OCAMLYACC) parser.mly

parser.ml: parser.mli parser.mly ast.cmo
	$(OCAMLYACC) parser.mly

lexer.ml: lexer.mll
	$(OCAMLLEX) lexer.mll

lexer.cmo: lexer.ml parser.cmo
	$(OCAMLC) -c lexer.ml

parser.cmo: parser.mli parser.ml
	$(OCAMLC) -c parser.mli
	$(OCAMLC) -c parser.ml

clean:
	rm -f *.cmo *.cmi lexer.ml parser.ml parser.mli ast.cmo ast.cmi

.PHONY: all clean
