


# Sultan Text Editor (نسخة تجريبية)

### مقدمة
تُعد **لغة السلطان** أول لغة برمجة في العالم تدعم الكتابة والتطوير بلغتين: **العربية والإنجليزية** ضمن نفس النص. كما أنها أول **مترجم عربي (Arabic Compiler)** يحول النصوص المكتوبة بالعربية إلى **لغة C**، مع إنتاج **كود C** جاهز للاستخدام.

### كيفية الاستخدام
اتبع الخطوات التالية لتثبيت وتشغيل محرر النص سلطان:

1. **استنساخ المستودع من GitHub:**
   **clone sultanc**
   ```bash
   git clone https://github.com/supax0/sultan-lang


الدخول إلى مجلد المشروع:
then you need to cd into the folder 
```bash
   cd sultan-lang
```


بعد الخطوه الاوله الان سوي

2. **تشغيل محرر السلطان:**
   Then run this command
   ```bash
   ./sultan.sh
   ```
4. **لتبدا الكتابه بالعربي**
   بسبب عدم وجود محرر كود عربي عملت محرر بسيط يتيح لك ان تكتب بالعربي لنسخه المبدائه
   لتبد المحرر
   #note if english skip this step
   If you are code in English you do not need to start alive or to stuo or even to give command realive. Those commands are built to make Arabic coding easier, for english just use any code editor of your chosen. the
   the file exstension of the sultanc is .sn and compile with sultanc -c <filename.sn>
```bash
   sultanc alive
```
   بعد ان تنتهي يجيب اغلاق خدمه المحرر عبر
```bash
   sultanc stop
```

من اجل اعاده تشغيل
```bash
   sultanc realive
```



الان تقدر تروح علي 127.0.0.1:5140
محرر خاص باللغه



 في السيرفر تقدر تسخدم الترمنل طبيعي فقط لفتح ملف 
 ```bash
 open <filename>
```

  للحفظ
  ```bash
  command+s
``` 
 الملف بينحفظ وقتها بعد كتابه النص تقدر تسوي
 ```bash
 sultanc -c <filename>
```

 للاسف الترمنل حاليا بالانجيلزي الي ان يتم التطوير الفكره حاليا انه توفير مكان لكاتبه النص العربيه مع ترمنل يدعم العربيه
 تقدر تكتب الكود في اي مكان ماانت مجبر تستخدم 
 ```bash
 sultan alive
```
 فقط وقت تنفذ الامر سوي 

 This can be used for english and Arabic compile files all same step, the only difference is the step of written the code.
 ```bash
 sultanc -c <filename.sn>
```
 يعني لو الملف اسمه 
 # exmalpe
  my file name is -> exmaple.sn
 ```bash 
 sultanc -c example.sn
```
  ملف السلطان 
  .sn
  مثال عن لغه السلطان

عرف القلعة () {
  اطبع("مرحبا من قلعة السلطان");
  }

  يعني هذا مثل 


  
<img width="216" alt="openexample" src="https://github.com/user-attachments/assets/796c60bb-8e92-4d83-88e6-26d1c7d1152e">

<img width="750" alt="codeexample" src="https://github.com/user-attachments/assets/15717d86-ac7d-4e01-b912-0b78aeb3f898">
<img width="209" alt="runexample" src="https://github.com/user-attachments/assets/358a1eaf-4c48-4f2a-bb31-e0176231dd12">

<img width="743" alt="outputexample" src="https://github.com/user-attachments/assets/f66d803f-8182-4aef-86aa-c454fd98e592">

<img width="166" alt="Screenshot 2024-10-16 at 12 07 09 AM" src="https://github.com/user-attachments/assets/d13fdb21-0486-46c4-80a0-6f62adda300a">



Sultan-lang
Sultan Programming Language


```bash
def main(){

    print("Hello Sultan"); #English

  
}
```




الملفات كلها بالعربي والانجليزي نفس الشي 
```bash
# هذا الملفات المخرجه للاسف حاليا جيب العمل مع الانجليزي جزايا لعدم وجود محرك يدعم العربي كامل ان شاء الله جاري التطوير 
target/ir
#The exc file will be in
target/<filename>
```


Both English and Arabic will generate a c file as IR file and also exc file in the 
```bash
# thise folder will be generated as steo if compilations 
target/ir
#The exc file will be in
target/<filename>
```

My goals

Objective: To develop a new low-level language, Sultan-lang, with an initial compiler written in English. The long-term vision is to rewrite the compiler in Arabic once the language is fully self-hosting, while maintaining Sultan-lang's core mission: to compile scripts written in multiple languages. At launch, Sultan-lang will support Arabic (ar), Spanish (es), French (fr), and English (en), with English being the language of the initial compilation scripts.

Rationale for Rewriting in Arabic:

English, while widely used in programming, has a relatively limited number of unique combinations (keywords, syntax, etc.). In contrast, Arabic offers a far richer set of unique combinations due to its linguistic complexity and historical significance as the original language of mathematics. Rewriting the compiler in Arabic will not only unlock new possibilities that English cannot achieve, but it will also enhance the language's flexibility and expressiveness. Additionally, Arabic's deep connection to Latin languages makes it an ideal candidate for a multi-language compiler.

Arabic: A Superior Semitic Language for Programming:

Arabic is a highly structured and semantically rich language, making it exceptionally well-suited for programming. Its root-based system allows for a vast array of word formations and syntactic flexibility, enabling more expressive and precise code. By leveraging Arabic's superior semantic structure, Arun-lang will be able to offer more powerful and versatile programming constructs, further distinguishing itself from other languages.

Arun-lang's unique ability to allow code to be written in any supported language (Arabic, Spanish, French, or English) while maintaining the integrity and functionality of the code demonstrates the compiler's versatility. This multi-language support is not just a feature but a fundamental aspect of Arun-lang's design, reflecting the global and inclusive vision of the language.

Future Impact:

This transition will pave the way for a new era in computer science. Preliminary research indicates that Arabic could achieve a 171 unique base system without redundancy or grammatical limitations, compared to the current 86-system base in English. This advancement has the potential to open new avenues in computing, pushing the boundaries of what can be achieved with multi-language compilers and fostering innovation in the global developer community.
