# Chapter 1 - C++ Basics

## Section 1 - Structure of a C++ program
Let's breakdown the code snippet bellow, line-by-line:

```C++
#include <iostream>
 
int main()
{
   std::cout << "Hello world!";
   return 0;
}
```

### Preprocessor directives
```C++
#include <iostream>
```

This is a preprocessor directive, it indicates that we want to use the contents of the library iostream, which is part of the Standard Library.

### Main
```C++
int main() {
    ...
    return 0;
}
```
The main function is the entry point of any program, all code is executed within and when it finishes it must always return an integer. If the returned number differs from 0, might be an indication of an error while executing our code, but this behavior is not mandatory. When it compiled, the binary contain references to the main loop in which is called to execute the program. The main functions can call another functions, as we will see further on.

### Functions
```C++
int max(int a, int b) {
    ...
    return result;
}
```
Functions are a collection of statements, it can or not return a value. The type returned by that function is indicated by the type declared in front of the function name. It's very similar to the main function syntax, after all the main function is also a function.

### Statements
```C++
std::cout << "Hello world!";
```
Statements are the smallest unit of computation on the C++ language. The statement above calls the `cout` (stands for character output) function from inside the standard library aka `std`, which we just imported with our preprocessor directive. Further on, with the help of the `<<` operator, the string `Hello world!` is passed for that function as a stream. The `cout` will then output the string in the console.

### Third-party libraries
The same functionality can be achieved with minor changes in our code. Let's say that we want to use the `fmt` library as a dependency of our project.

```C++
#include <fmt/format.h>

int main()
{
  fmt::print("Hello World!");
  return 0;  
}
```

Or `spdlog`, for instance.

```C++
#include <spdlog/spdlog.h>

int main()
{
  spdlog::info("Hello World!");
  return 0;  
}
```

See that `spdlog` library generates a very fancy output. This correlates more to the real world, where your program sends logging information to the console or a file and therefore, can help you to solve problems or bugs.

### Questions
1. What is a statement? R: It's the smallest computation unit in the C++ language. It's the most common in a program.

2. What is a function? R: It's a collection of statements. A function can or not return a value, the type of that value is declared in the function declaration, together with it's name.

3. What is the name of the function that all programs must have? R: main. The entry point of every program.

4. When a program is run, where does execution start? R: In the first statement inside the main function.

5. What symbol are statements in C++ opften ended with? R: A semicolon `;`.

6. What is a syntax error? R: It's when someting inside our code is declared incorrectly, so the compiler does not know exactly what we meant to do with it and throws an error back at compile-time.

7. What is the C++ Standard Library? R: It's a collectin of libraries that comes by standard in any C++ compliant environment. They are developed by the standards comitee, and very often, are very well documented and optimized.

## Section 3 - Introduction to variables

### Objects and variables
As is stated in [learncpp.com](https://www.learncpp.com/cpp-tutorial/introduction-to-variables/) : 
`All computers have memory, called RAM (short for random access memory), that is available for your programs to use. You can think of RAM as a series of mailboxes that can be used to hold data while the program is running. A single piece of data, stored in memory somewhere, is called a value`.

### Variable instantiation

In short terms, when we declare a variable, we are basically assigning a specific memory address, defined on runtime or not, to an object within our program. Then, every modification that we apply to this object, will correspond to an equal modification in the memory address which the variable was assigned to. 

We can share references of that memory location to different objects using pointers. When the object goes out of scope, it imediatelly is deleted, so it's memory can be freed. If that doesn't happens, we are facing a very common and recurrent bug, the infamous `memory leak`.

```C++
{             // Inner scope
  int foo;    // Object instantiation
}             // Object is destroyed, memory freed
```

### Questions

1. What is data? R: Data is the main reason why we write computer programs, so we can manipulate then. Can be from any source, e.g.: file, network, user input, etc.

2. What is a value? R: A value is the data that is stored inside an object.

3. What is a variable? R: A variable is an object that holds a memory address and a value.

4. What is an identifier? R: Is the name of our object.

5. What is a type? R: Type is defined within object instantiation, and specify the type of data which will be stored.

6. What is an integer? R: Integer is an object type, that only holds integer numbers. There are many integer sizes supported by the compiler, from 8-bit to 64-bit integer. Usually, when defining only with `int` statement, it corresponds to 16-bit integer. 

## Section 4 - Variable assignment and initialization
Check out this [blog post](https://herbsutter.com/2013/08/12/gotw-94-solution-aaa-style-almost-always-auto/) of Herb Sutter, one of the ISO C++ comitee members, on a modern approach of assigning and initializing objects with use of the `auto` keyword and list initialization combination.

### Copy initialization
```C++
  int foo = 5;
  ...
  auto bar = 5;
```

### Direct initialization
```C++
  int foo(5);
  ...
  auto bar = int(5);
```

### List initialization
```C++
  int foo = int {5};
  ...
  auto bar {5};
```

### Questions
1. What is the difference between initialization and assignment? R: Assignment takes place when using copy assignment operator to, again, assign a value to a previously created variable. On the other hand, initialization is the process of creating an object and defining it's type. You can use three different methods of initialization when in combination of a assignment, copy, direct and list initialization.

2. What form of initialization should you be using? R: Preferable method is list initialization, which disables completly narrowing conversion and, as any of the other forms, avoids undefined behavior.

## Section 5 - Introduction to iostream: cout, cin and endl

### Questions
Consider the following code:

```C++
#include <fmt/format.h>
#include <iostream>

int main()
{
  fmt::print("Insert a integer number: ");

  int x{ };
  std::cin >> x;

  fmt::print("You inserted number {}\n", x);

  return 0;  
}
```

Run this program multiple times and describe what happens when you enter the following types of input instead:

- A letter, such as h.

  R: Output is 0. Expects a valid number.

- A number with a fractional component.

  R: Input number gets floored (0.9 >> 0 | 0.5 >> 0).

- A small negative integer, such as -3.

  R: Number is valid, because it's a signed integer.

- A word, such as Hello.

  R: Output is 0. Expects a valid number.

- A really big number (at least 3 billion).

  R: Overflow. Variable accepts only signed 32-bit integers (-2'147'483'648 to 2'147'483'647)

  ```
  Insert a number: 3000000000000.
  You inserted number 2147483647
  ```
