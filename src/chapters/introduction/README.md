## Introduction

Workflow on general software development.

### Step 1: Define the problem that you would like to solve
Here are a few examples:

- “I want to write a program that will allow me to enter many numbers, then calculates the average.”
- “I want to write a program that generates a 2d maze and lets the user navigate through it. The user wins if they reach the end.”
- “I want to write a program that reads in a file of stock prices and predicts whether the stock will go up or down.”

### Step 2: Determine how you are going to solve the problem
Typically, good solutions have the following characteristics:
- They are straightforward (not overly complicated or confusing).
- They are well documented (especially around any assumptions being made or limitations).
- They are built modularly, so parts can be reused or changed later without impacting other parts of the program.
- They are robust, and can recover or give useful error messages when something unexpected happens.

### Step 3: Write the program
That's the easy part.

### Step 4: Compiling your source code
Compiler doing compiler things. Compiler does compile each `.cpp` file that is a dependency of your program, and generating an `.o` file as an output. In this part, syntax errors may be generated.

### Step 5: Linking object files and libraries
Linker doing linker things. Linking `.o` files, together with standard library and all other libraries that requires, to a single executable.

### Steps 6 & 7: Testing and Debugging
And that's the fun part. Here you can use any test library like `Google Test` or mocking library like `Google Mock`. And also for the debugging side, `GBD` is a very powerful tool (available on Linux as part of the GNU tools).


