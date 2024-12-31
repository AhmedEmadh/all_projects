# C Language Lexer (Scanner) Project

<p align="center"><strong>A simple lexer (scanner) implementation in C++ that tokenizes C language code to aid in parsing.</strong></p>

---

## Table of Contents

- [About the Project](#about-the-project)
- [Features](#features)
- [Tech Stack](#tech-stack)
- [Installation](#installation)
- [Usage](#usage)
- [Screenshot](#screenshot)

---

## About the Project

This project implements a **lexer** (scanner) that reads and tokenizes C code, transforming it into a sequence of tokens. The lexer is built to help with parsing in a C compiler, and it can process both C source files and raw C code strings. It uses regular expressions and state machines to identify different types of tokens, such as identifiers, numbers, strings, operators, reserved words, and special characters.

---

### Key Features:

- **Tokenization**: The lexer takes C code as input and breaks it into a list of tokens, which are essential for the subsequent stages of compilation.
- **Error Detection**: It detects errors such as invalid symbols (like '@') or variables starting with a number.
- **Token Types**: The lexer can classify tokens as identifiers, numbers, strings, operators, reserved words, and special characters.

---

### Files in the Project:

- **Lexer.h**: The main header file containing the class declaration and tokenization logic.
- **Lexer.cpp**: Contains the methods of the `Lexer` class, including tokenization and error handling.
- **Token.h**: Defines the `Token` class, which holds information about each token.
- **Token.cpp**: Implements the `Token` class methods.
- **TokenType.h**: Defines an enumeration for the different token types used by the lexer.
- **main.cpp**: The entry point of the program that tests the lexer functionality.

---

## Features

- **C Language Tokenization**: Supports tokenization of C code into a sequence of tokens.
- **Error Handling**: The lexer detects certain invalid patterns in the input code, such as a symbol '@' or invalid variable names.
- **File Input**: The lexer can read from a file containing C code, enabling automated tokenization of source files.
- **State Machine Logic**: Implements a state machine to handle different tokenization states like number parsing, identifiers, string literals, and comments.

---

## Tech Stack

- **Languages & Tools**:
  - C++ programming language.
  - Standard C++ libraries for file handling, string manipulation, and data structures.
  - Custom logic for lexing and token classification.

---

## Installation

### Prerequisites

To run this project, you will need:

- A C++ compiler (e.g., GCC or Clang).
- A text editor or IDE to edit C++ files.

---

### Steps to Run:

1. Clone the repository:
   
   ```bash
   git clone <repository-url>
   ```

2. Navigate to the project folder:
   
   ```bash
   cd lexer-project
   ```

3. Compile the `main.cpp` file using a C++ compiler:
   
   ```bash
   g++ main.cpp -o lexer
   ```

4. Run the program:
   
   ```bash
   ./lexer
   ```

---

### Usage

1. **Tokenizing a File**:  
   To tokenize a C source code file, simply pass the filename to the `Lexer` constructor (as seen in `main.cpp`):
   
   ```cpp
   Lexer lexer("Testfile.txt");
   lexer.scan();
   ```

2. **Scanning and Printing Tokens**:  
   After scanning, you can retrieve and print the tokens as follows:
   
   ```cpp
   vector<string> tokens = lexer.getTokens();
   for (auto token : tokens) {
       cout << "  " << token << endl;
   }
   ```

3. **Custom Input**:  
   You can modify the `Lexer` class to accept string inputs or read different files for tokenization.

---

### Screenshot

![Screenshot](https://github.com/AhmedEmadh/all_projects/blob/master/C%2B%2B%20Projects/C_Lexer/Screenshot%20-%20C%20compiler.png)
