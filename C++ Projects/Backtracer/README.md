# Backtracer Project

<p align="center"><strong>A simple and lightweight backtrace logging system for tracking function calls in C++ programs.</strong></p>

---

## Table of Contents

- [About the Project](#about-the-project)
- [Features](#features)
- [Tech Stack](#tech-stack)
- [Installation](#installation)
- [Usage](#usage)
- [Screenshot](#screenshot)
- [Example Code](#example-code)

---

## About the Project

The **Backtracer** is a simple C++ utility that helps track function calls and the execution flow in a program. It logs when a function is entered and exited, creating a "backtrace" of the program's execution. This is useful for debugging, performance profiling, or understanding the flow of function calls in a program.

This project was created to easily track function calls in C++ programs without needing to manually write repetitive backtrace logic.

---

## Features

- **Function Call Tracking**: Automatically tracks function calls with a simple macro system.
- **Backtrace Printing**: Prints the full backtrace of function calls at any point in your program.
- **Macro Simplification**: Provides macros like `EnterFn`, `ExitFn`, and `PRINT_BT` for easy usage.
- **Lightweight**: Minimal performance overhead with just the necessary logging.

---

## Tech Stack

<p><strong>Languages & Tools:</strong></p>
<ul>
    <li><a href="https://en.cppreference.com/w/cpp">C++ Programming Language</a></li>
    <li>Standard C++ libraries for input/output and function call tracking.</li>
</ul>

---

## Installation

### Prerequisites

- A C++ compiler (such as GCC or Clang) installed on your machine.
- A terminal or command prompt to compile and run the program.

### Steps

1. Clone the repository:
   
   ```bash
   git clone https://github.com//AhmedEmadh/all_projects
   ```

2. Navigate to the project directory:
   
   ```bash
   cd backtracer
   ```

3. Compile the code:
   
   ```bash
   g++ main.cpp Backtrace.cpp -o Backtrace.exe
   ```

### Usage

- **Using the Macros**: In your program, you can include the `Backtrace.h` file and use the macros `EnterFn`, `ExitFn`, and `PRINT_BT` to track function calls.
  
  - **`EnterFn`**: Call this macro at the beginning of any function you want to track.
  - **`ExitFn`**: Call this macro at the end of a function to mark the exit point.
  - **`PRINT_BT`**: Call this macro whenever you want to print the current backtrace.

- **Running the Program**: After compiling the code, you can run it to see the backtrace in action.
  
  ```bash
  ./Backtrace.exe
  ```

### Screenshot

![Alt text](https://github.com/AhmedEmadh/all_projects/blob/master/C%2B%2B%20Projects/Backtracer/Screenshot.png)

### Example Code

```cpp
#include <iostream>
#include "Backtrace.h"

// Function A
void functionA() {
    EnterFn; // Equivalent to Backtrace::pushRecord(__func__);
    // Simulate some work
    std::cout << "Inside functionA\n";
    ExitFn; // Equivalent to Backtrace::PopRecord();
}

// Function B
void functionB() {
    EnterFn; // Equivalent to Backtrace::pushRecord(__func__);
    functionA(); // Calling functionA
    ExitFn; // Equivalent to Backtrace::PopRecord();
}

// Main function
int main() {
    EnterFn; // Equivalent to Backtrace::pushRecord(__func__);
    functionB(); // Calling functionB
    ExitFn; // Equivalent to Backtrace::PopRecord();

    // Print the backtrace
    PRINT_BT; // Equivalent to Backtrace::printAllRecords();

    return 0;
}
```

Expected Output:

```
Enter to [main]
Enter to [functionB]
Enter to [functionA]
Inside functionA
Exit From [functionA]
Exit From [functionB]
Exit From [main]
Backtrace as follows:
0- main
1- functionB
2- functionA
Backtrace is Finished
```
