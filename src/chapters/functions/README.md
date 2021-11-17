# Functions

`"A function is a reusable sequence of statements designed to do a particular job." [...] "Functions provide a way for us to split our programs into small, modular chunks that are easier to organize, test, and use. Most programs use many functions. The C++ standard library comes with plenty of already-written functions for you to use -- however, it’s just as common to write your own. Functions that you write yourself are called user-defined functions."` [learncpp.com](https://www.learncpp.com/cpp-tutorial/introduction-to-functions/)

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

## Function return values

Consider the code below:

```C++
#include <iostream>

void get_value_from_user() {
    std::cout << "Enter an integer: ";
    int input{};
    std::cin >> input;
}

int main() {
    // Ask for user input
    get_value_from_user(); 

    int num{}; 
    std::cout << num << " doubled is: " << num * 2 << '\n';

    return 0;
}
```

This program is composed of two parts: first, we ask the user to input a number; second, we print out what double that number is.

While this program compiles and generates an executable successfully, it doesn't quite work the way is supposed to. The issue is that, no matter what number the user input, we get the same result back in the console.

Can you think a way why is this happening?

There are two flaws in our code.

1. The function `get_value_from_user()` never returns a value, we know that because of the `void` return type on the function declaration. In order to fix it, it should return something, in this case, the input number (which is an `int`) from the user. Also, the `return` statement should be used inside of the scope of the function in order to return the variable with the number entered by the user.
    ```C++
    ...
    int get_value_from_user() { // `int` as return type
        std::cout << "Enter an integer: ";
        int input{};
        std::cin >> input;
        return input; // returning the input value
    }
    ...
    ```

2. We initialize a variable `num` in the `main()` scope but we never assign a value to it, so it assumes the default initialization value which is zero. So in order to fix it, we should initialize the variable `num` assigning the value returned by the function `get_value_from_user()`.
    ```C++
    ...
    int main() {
        ...
        // Assigning the value returned
        int num = get_value_from_user();
        ...
    }
    ...
    ```

So by now, our program should run sucessfully the way it is intended to.

Let's increase our difficulty by asking the user to enter two different numbers, and as a result it should print out the sum of those values.

How would you implement that?

One step on making this code clean and maintanable is already done, which is following the principle `DRY` or `Don't Repeat Yourself`. Do you agree that asking the user to input two different numbers is basically calling the function `get_value_from_user()` two times and storing each returned value in a different variable? 

Let's see how this translates to code.

```C++
#include <fmt/format.h>
...
int main() {
  int number_one = get_value_from_user();
  int number_two = get_value_from_user();
  
  fmt::print("{} + {} = {}\n", number_one, number_two, number_one + number_two);
  return 0;  
}
```

Producing the following output:
```
❯ ./functions
Enter a number: 2
Enter a number: 5
2 + 5 = 7
```

Notice that we didn't changed a single line of code inside the `get_value_from_user()` function declaration.