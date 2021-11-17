# Basics
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

## Variable assignment and initialization
Check out this [blog post](https://herbsutter.com/2013/08/12/gotw-94-solution-aaa-style-almost-always-auto/) by Herb Sutter, one of the ISO C++ comitee members, on a modern approach of assigning and initializing objects with use of the `auto` keyword and list initialization combination.

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