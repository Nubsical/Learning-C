# K&R Study Notes

Log of working through *The C Programming Language*, 2nd edition.
Format: dated entries, chapter summaries when I finish one, questions I want to come back to.

---

## Chapter 1 - Tutorial Intro

### Summary
April 24, 2026
Chapter 1 was mostly a giant runthrough of the basic format and functions of C. C doesn't have concatination in the same way Java/Python do; instead, the %x is used to embed variables, whether it would be ints, strings, chars, etc into a string. Lines are read on input through iterating each character, each of which is literally an integer which corresponds to values on an ascii table for binary representation in the memory. A string is just a collection of chars with \0 at the end to signify the end. Files end with EOF (end of file), a special character to indicate the end. Variables hoisted outside of main() are referenced via "extern", though its better practice to minimize use of external variables due to unintentional uses/modifications. 

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

---

## Chapter 2 - Types, Operators, Expressions

### Notepad (ignore, just for annotating, will delete)




### Summary

### Understood/Didn't Understand
April 25, 2026
- They mention "Two's complement" but don't expand on it when referring to signed integers, gonna have to manually look into what that is.
- What is the purpose of headers like `<limits.h>`
- How are floats structured differently that poses challenges to discovering the maximum val. 
April 26, 2026
- Why is int truncation behavior when divided or modulod machine dependent?
### Connection to drone/CUDA

### Things worth remembering
April 25, 2026
- Strings CAN be concatendated, i guess they will show later
- first char of var name must be letter with _ being letter as well. 
- first 31 characters significant when naming variables
- ints reflect natural size of integers on host machine but i'm pretty sure nowadays its a specific size. Floats are considered single-precision while double's are double precision.
- short < int < long, shorts generally 16 bits, ints generally 16 or 32, longs generally >32
-unsigned numbers are positive or 0, "obey laws of arithmetic modulo 2^n" where n is # of bits in type". Follows standard of binary where range is 0-255. 
- signed between -128 to 127. printable characters are always positive.
- space used depends both on datatype and how it is used. Compilers determine space used by datatype, which varies between compilers, meaning some datatypes like float and double can be equal.
- when referring to an unsigned int, you should use %u and %d is for signed and that can't represent the full range of unsigned #s
- spacing of floats depend on size, with spacing increasing as the number increases.
- leading 0 on integer means octal, 0x means hexadecimal, both of which can be short/long and signed/unsigned
- long constants written with L after, # too big to fit in ints are taken as long, unsigned values have U suffix, and UL is unsigned long. Intuitive with datatype names. Floating point constants are considered doubles unless labeled with F.
- \ooo can be used to represent octals and having an x for the first o can be used to represent hexadecimal, specifically for ascii
- strings are concatenated in C when they are just following each other like "hello" "world" is just "hello world"
April 26, 2026
- enumerations can be helpful both for convenience when setting variables with consecutive values and checking type validity during compilation compared to constants
- binary operators work on two elements while unary operators only 1 (i++, -i, !i). Unary has highest precendence
- relational operators (`<, >, <=, >=`) have same precedence, but higher precedence than == and !=, equality operators. Think of comparing values vs whether they are literally equal or nah. Both relational and equality operators are lower in precendence to arithimic operators.
- && has higher precedence than ||, both of which have low precedence allowing for seperation without parenthesis of diff comparisons
- when compared, the comparison is evaluated to 0 (false) or 1(true) rather than direct boolean. 
- chars have a lot of flexibility because of their short num nature
- `<ctype.h>` gives functions for tests/conversions for characters like isdigit() or tolower()
- because machines vary, you should explicitly specify signed or unsigned when using characters for non-character related purposes 
- during binary operations of different types, the lower is converted to higher type (short converted to long, int converted to long). Only exception is floats, which convert doubles to floats to save storage in large arrays
- -1L < 1U and -1L > 1UL. First condition is true because 1U, which is an int that's unsigned, gets promoted to the "larger" type of the two (L) which is signed. So 1U, an unsigned int, becomes signed long. BUT, with -1L > 1UL, both are longs. C then interprets the L (signed long) as being "smaller" than UL (unsigned long), converting the smaller -1L, a signed long, to an unsigned long. Unsigned -> signed does some conversion i think i'll learn about that converts it to a large + num by the way it converts it
- UNSIGNED IT HIGHER THAN SIGNED
- for assignments, its a lot simpler, just right type is left type
- despite signed or unsigned, chars -> ints



### Filling "Didn't Understand" Gaps
April 25, 2026
- Signed ints/"two's complement" confusion: not that deep. signed its just use the first bit on the num to represent + or - (0 or 1 respectively), that cuts it from 255 to 127 being the max num since 2^7 isn't there anymore. 
- purpose of datatype headers confusion: they provide constant values specific to machines that represent constrictions like max of that datatype or min to remove need for guesswork, and also make it more adaptable between systems.
- floats confusion: floats follow a specific formula, value = 1.mantissa * 2^exponenent. To find the max you would want to keep multiplying a float by two until it reaches is maximum as multiplying by two is essentally adding 1 to the exponenet, and when the exponenet reading the maximum possible value, the float is at it's maximum.
April 26, 2026
- truncation being machine dependent confusion: back then, there wasn't a standard so some cpus truncated to -infinity vs to 0. Today, the standard is 0. 

