# Chapter 2 - C++ Basics: Functions and files

## Section 1 - Introduction to functions

### Definition

`"A function is a reusable sequence of statements designed to do a particular job." [...] "Functions provide a way for us to split our programs into small, modular chunks that are easier to organize, test, and use. Most programs use many functions. The C++ standard library comes with plenty of already-written functions for you to use -- however, it’s just as common to write your own. Functions that you write yourself are called user-defined functions."` [learncpp.com](https://www.learncpp.com/cpp-tutorial/introduction-to-functions/)

### Syntax
```C++
return_type identifier(argument_type argument_identifier)
{
    // code here
    return;
}
```

- `return_type`: Explicitly tells the compiler which type will be returned from the function (e.g. `void`, `int`, ...). This is very different from dynamic typed programming languages (e.g. Python, Javascript), where you, either, don't need to declare which type you're returning from a function, or, don't need to declare you're returning at all.
- `identifier`: Function's name, used for calling the function.
- `argument_type`: Tells the compiler what type the argument should be, like the `return_type`.
- `argument_identifier`: Argument's name, used for passing values or references from the caller to inside the function scope.
- `return`: Specifies where the function should return (end). Also, when using a `return_type` different than `void`, should use this to return the value to the function caller.

### Disclaimer
Nested functions declarations are not supported, unlike Javascript for example. So the snippet below is ilegal and is not accepted by the compiler, but will work if you use JS, for example.

```C++
int main()
{
    void func()
    {
        // this will not compile
    }

    return 0;
}
```

### Quiz Time
1. In a function definition, what are the curly braces and statements in-between called?
    R: It's the function body or, also known as, function scope.


2. What does the following snippet should print? Do not compile this program, just trace the code yourself.
    ```C++
    #include <iostream> // for std::cout
 
    void doB()
    {
        std::cout << "In doB()\n";
    }
    
    void doA()
    {
        std::cout << "In doA()\n";
    
        doB();
    }
    
    // Definition of function main()
    int main()
    {
        std::cout << "Starting main()\n";
    
        doA();
        doB();
    
        std::cout << "Ending main()\n";
    
        return 0;
    }
    ```
    R:
    ```
    Starting main()
    In doA()
    In doB()
    In doB()
    Ending main()
    ```

### Section 2 - Function return values
