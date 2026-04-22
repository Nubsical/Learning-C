# K&R Study Notes

Log of working through *The C Programming Language*, 2nd edition.
Format: dated entries, chapter summaries when I finish one, questions I want to come back to.

---

## Chapter 1 - Tutorial Intro

### Summary

### Understood/Didn't Understand
April 19, 2026
- Don't get the practical difference between import and include. I get that import is pulling a specific library while include is almost like copying function code, but I feel like it goes deeper than this.
April 20, 2026
- How can C just store chars as ints if they're 2 different datatypes.
April 22, 2026
- Why does there have to be a declaration before a function definition in C

### Connection to drone/CUDA
April 19, 2026
- C runs the program on the main function. In the case of communication between my drone's flight controller '<-->' the raspberry pi/orin nano, it would obviously be two different "main" functions... two different environments that communicate with one another.
- datatype conversions along with bits corresponding to datatypes is important for understanding how memory is stored, transmitted, and used via the flight controller and CUDA. 

### Things worth remembering
April 19, 2026
- \#include \<stdio.h\>, this almost "copy an pastes" text library functions rather than importing 
- To linux, file extensions are cosmetic. Thus, whether or not the compiled file is in .out format does not matter, for now at least
- Errors regarding syntax and stuff given during compiling. Obviously runtime errors exist though.
- datatypes didn't know: short (short int), long(long int) 
- Integers truncate so it is better to multiply a var then divide rather than multiplying by fraction form.
- %xd references respective integer within printf function. x refers to min width, adding spaces in front to fulfill min requirement. %xf same for floats, allowing decimal for min decimal
April 20, 2026
- conditional operators (!=) take precedene over assignment (=)
- the code in example 1-5 only sees the characters after enter is pressed, from which getchar() is called for each one
- getchar() behaves almost as a loop iterating through the stream via a pointer. Once a character is gotten, it moves on.
April 21, 2026
- states can be useful to simplify iterating until x. In the case of seperating words and removing whitespaces, getting to the next word.
- unlike java, functions don't require a return.
April 22, 2026
- in C, parameter vars are copies. Similar to Python where they are copies but mutable types such as arrays point to the original address/modifications are reflected in the original
- Strings end with \0 to signify end. An array of characters that is null terminated (has the \0 at the end) will be treated as a string when called
- usual for extern variables to be in allocated header file, ending in .h, and added via #include. seen with stdio.h
- don't try to maximize extern var use since that could result in uninteded uses and modifications.
### Filling "Didn't Understand" Gaps
April 19, 2026
- Import vs include confusion: C, being the low level language it is, lacks a built-in module system like Java, limiting it to just copying via include and linking. Import handles things like loading the module, avoiding duplicate loads, controlling namespace, and handling dependencies.
- Chars/ints confusion: chars in C are essentailly just ints (1 byte) but more abstract, representing integers as character values. What's sick is that the way it encodes it adapts depending on the system you're using. Some systems may encode it via ASCII while others may use a different encoding format, so two of the same character on two diff systems can represent different int values.
April 22, 2026
- Function declaration vs actual body: alright so this is kinda cool. Initially, the computer reads the code top to bottom when compiling it. When it reads the statement calling the function, it needs to know the return type at that moment to determine whether or not it is correct syntax-wise and ensuring the call matches the function signature. You could just avoid having a declaration by writing the function at the top, but I don't know how people these days format their code since this book was written 50 years ago.
