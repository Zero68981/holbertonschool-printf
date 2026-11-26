# holbertonschool-printf

 ## Project Description

The `_printf()` project consists of recreating the standard C library function `printf()`.

The main goal is to understand how formatted output works in C by implementing our own version of `printf()`.

Throughout this project, we explore variadic functions, format strings, conversion specifiers and low-level output using the `write()` function.

This project helps us strengthen our understanding of C programming and improve our problem-solving skills.

## What does it do?

our "homemade" printf function written from scratch takes the a forma of string variable and numbers of arguements formats them and write the results  adn then returns all the characters printed.

supported conversion specifiers: `%c`, `%s` and `%%`.

## Conversion specifiers

our homemade printf function supports the following specfiers;

%c

Prints a single character.

_printf("%c", 'A');

%s

Prints a string of characters.

_printf("%s", "Hello");

%%

Prints the percentage symbol (%).

_printf("100%%");

allowing the function handle different types o datas and format accordingly.


