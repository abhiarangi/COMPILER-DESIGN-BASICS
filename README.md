# COMPILER-DESIGN-BASICS

 **COMPANY**: CODTECH SOLUTIONS

 **NAME** : ARANGI ABHISHEK

 **INTERN ID**  : CT08WCM

 **DOMAIN** : C PROGRAMMING

 **DURATION** : 4 WEEKS 

 **MENTOR** : NEELA SANTHOSH KUMAR

**DESCRIPTION**

A lexical analyzer, often referred to as a scanner, is a crucial component of a compiler. It is responsible for reading the source code and breaking it down into meaningful tokens such as keywords, operators, identifiers, and more. Building a simple lexical analyzer in C requires understanding string manipulation, file handling, and fundamental programming constructs. 

Lexical analysis involves processing an input file line by line and character by character to group sequences of characters into tokens. These tokens represent elements such as:
 **Keywords:** Reserved words in a programming language (e.g., `int`, `for`, `return`).
 **Operators:** Symbols used for operations (e.g., `+`, `-`, `*`, `=`).
 **Identifiers:** Names given to variables, functions, and arrays (e.g., `x`, `myFunction`).


### **Structure of the C Program**
The program can be divided into the following steps:
1. Open and read the input file.
2. Define arrays for keywords and operators.
3. Process each character or word in the file.
4. Compare substrings with predefined lists to identify keywords and operators.
5. Use conditions to differentiate identifiers.
6. Write output to the console or another file.

 **Explanation of Code**
1. **Keywords and Operators Arrays:** The program uses arrays to store predefined keywords and operators. The functions `isKeyword()` and `isOperator()` help in checking whether a word or character matches these arrays.
2. **Reading the File:** Using `fgetc()`, the program reads the file character by character. 
3. **Classifying Tokens:** 
   - If the character is alphabetic (`isalpha()`), it is part of an identifier or keyword. The program collects subsequent alphanumeric characters (`isalnum()`) to form a complete word.
   - If the character is an operator, it checks using the `isOperator()` function.
4. **Output Tokens:** Identified keywords, operators, and identifiers are printed.

 **Features and Limitations**
 **Features:** This program identifies keywords, operators, and identifiers efficiently. It processes the input file in a linear fashion and classifies tokens based on straightforward comparisons.
 **Limitations:** It assumes operators and keywords are single-character or single-word tokens. More complex tokens (e.g., multi-character operators like `<=`) would need additional logic.


**OUTPUT**

![Image](https://github.com/user-attachments/assets/5d70e05c-0321-4133-9be1-dc988591eb84)
