### Ispeak

**USECASE**: This module acts as the initial layer within the Sultan compiler architecture.

# Compilation Order:
- **1**: ocamlc -c -I +str -I compiler/colorizer -I compiler/lang compiler/lang/translator.ml
- **2**: ocamlc -o ispeak -I +str -I compiler/colorizer -I compiler/lang \
  str.cma \
  compiler/colorizer/colorizer.cmo \
  compiler/lang/translator.cmo \
  compiler/lang/ispeak.ml

# How it Works
> Must reside at the same directory level as the `settings` folder, which must contain:

### **Step One**: Directory Structure 
- **Path**: <Ispeak>/<AddLang><Native>
- **Files**: <Syntax.en>, <Syntax.ar>, <Syntax.fr>, etc., with <Syntax.en> serving as the base.

### **LangSettings.sns** File
This file contains flags for files specified in **Step One**.
#### Example of `LangSettings.sns`:
```plaintext
#ID; SupportedLanguages; FlagType;
1; Arabic; -ar;
2; French; -fr;
