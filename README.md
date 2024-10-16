بسم الله الرحمن الرحيم



In the name of Allah, the Most Gracious, the Most Merciful



هذا هي النسخه التجربيه لمحرر النص سلطان. لغه السلطان تعتبر اول لغه بالعالم التي تدعم العربيه والانجليزيه من ضمن تحرير النص. وتعتبر اول (Arabic compiler) للغه العربيه التي تدعم تحويل النص الي لغه c-lang ويتم اخراج c كود. ممكن نستخدم للغه بهذي الطريقة.
اول خطوه وهي 

git clone https://github.com/supax0/sultan-lang

بعدها
cd sultan-lang
chmod +x sultan.sh
./sultan.sh
بعد تحميل وتشغيل ملف sultan.sh 
لان اغلب محررات الكود ماتدعم العربيه لغه السلطان موجود بالقلعه سيرفر بسيط لكتابه الكواد ،سيتم تطويره باذن الله.

بعد الخطوه الاوله الان سوي
sultanc alive

الان تقدر تروح علي 127.0.0.1:5140
محرر خاص باللغه
لتسكير السيرفر 
sultanc stop
 لعاده التشغيل
 sultanc realive

 في السيرفر تقدر تسخدم الترمنل طبيعي فقط لفتح ملف 
 open <filename>
  للحفظ
  command+s 
 الملف بينحفظ وقتها بعد كتابه النص تقدر تسوي
 sultanc -c <filename>

 للاسف الترمنل حاليا بالانجيلزي الي ان يتم التطوير الفكره حاليا انه توفير مكان لكاتبه النص العربيه مع ترمنل يدعم العربيه
 تقدر تكتب الكود في اي مكان ماانت مجبر تستخدم 
 sultan alive
 فقط وقت تنفذ الامر سوي 
 sultanc -c <filename>
 يعني لو الملف اسمه 
 exmaple.sn
 sultanc -c example.sn
  ملف السلطان 
  .sn
  مثال عن لغه السلطان

عرف القلعة () {
  اطبع("مرحبا من قلعة السلطان");
  }

  يعني هذا مثل 
  sultan alive
  touch test.sn
  open test.sn
| ![openexample](https://github.com/user-attachments/assets/796c60bb-8e92-4d83-88e6-26d1c7d1152e) | ![codeexample](https://github.com/user-attachments/assets/15717d86-ac7d-4e01-b912-0b78aeb3f898) |
|:---:|:---:|
| ![runexample](https://github.com/user-attachments/assets/358a1eaf-4c48-4f2a-bb31-e0176231dd12) | ![outputexample](https://github.com/user-attachments/assets/f66d803f-8182-4aef-86aa-c454fd98e592) |



Sultan-lang
Sultan Programming Language



def main(){

    print("Hello Sultan"); #English

  
}
My goals

Objective: To develop a new low-level language, Sultan-lang, with an initial compiler written in English. The long-term vision is to rewrite the compiler in Arabic once the language is fully self-hosting, while maintaining Sultan-lang's core mission: to compile scripts written in multiple languages. At launch, Sultan-lang will support Arabic (ar), Spanish (es), French (fr), and English (en), with English being the language of the initial compilation scripts.

Rationale for Rewriting in Arabic:

English, while widely used in programming, has a relatively limited number of unique combinations (keywords, syntax, etc.). In contrast, Arabic offers a far richer set of unique combinations due to its linguistic complexity and historical significance as the original language of mathematics. Rewriting the compiler in Arabic will not only unlock new possibilities that English cannot achieve, but it will also enhance the language's flexibility and expressiveness. Additionally, Arabic's deep connection to Latin languages makes it an ideal candidate for a multi-language compiler.

Arabic: A Superior Semitic Language for Programming:

Arabic is a highly structured and semantically rich language, making it exceptionally well-suited for programming. Its root-based system allows for a vast array of word formations and syntactic flexibility, enabling more expressive and precise code. By leveraging Arabic's superior semantic structure, Arun-lang will be able to offer more powerful and versatile programming constructs, further distinguishing itself from other languages.

Arun-lang's unique ability to allow code to be written in any supported language (Arabic, Spanish, French, or English) while maintaining the integrity and functionality of the code demonstrates the compiler's versatility. This multi-language support is not just a feature but a fundamental aspect of Arun-lang's design, reflecting the global and inclusive vision of the language.

Future Impact:

This transition will pave the way for a new era in computer science. Preliminary research indicates that Arabic could achieve a 171 unique base system without redundancy or grammatical limitations, compared to the current 86-system base in English. This advancement has the potential to open new avenues in computing, pushing the boundaries of what can be achieved with multi-language compilers and fostering innovation in the global developer community.
