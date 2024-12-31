# Simplified Advanced Encryption Standard (SAES)

<p align="center"><strong>A lightweight implementation of the Simplified Advanced Encryption Standard (SAES) using C programming language.</strong></p>

---

## Table of Contents

- [About the Project](#about-the-project)
- [Features](#features)
- [Tech Stack](#tech-stack)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

---

## About the Project

The Simplified Advanced Encryption Standard (SAES) is a lightweight implementation of encryption and decryption operations based on a reduced version of the Advanced Encryption Standard (AES). It is commonly used as an educational tool to understand the fundamentals of cryptography and symmetric key encryption.

Key Highlights:

- Encrypts and decrypts data using a simplified block cipher algorithm.
- Demonstrates the basic principles of substitution-permutation networks (SPN).
- Implemented in C programming for maximum performance and portability.

This project was created as part of a university exercise in year 2023 to deepen understanding of cryptographic algorithms.

## Screen Shots

<h3>Encryption</h3>
<p align="center">
    <img src="https://github.com/AhmedEmadh/all_projects/blob/master/C%20Projects/Simplified%20Advanced%20Encryption%20Standard/screenshot%20Encryption%20example.png" alt="Project Screenshot" style="max-width: 100%;">
</p>
<h3>Decryption</h3>
<p align="center">
    <img src="https://github.com/AhmedEmadh/all_projects/blob/master/C%20Projects/Simplified%20Advanced%20Encryption%20Standard/screenshot%20Decryption%20example.png" alt="Project Screenshot" style="max-width: 100%;">
</p>
---

## Steps to Compile and Run

### 1. Compile the `main.c` file using GCC

First, compile the `main.c` source file to create an executable (`main.exe`) with the following command:

```bash
gcc main.c -o main.exe
```

### 2- Enter This Command in termnal

```bash
main.exe ENC 6DF4 42FA
```

the first paramenter is Data (6DF4) and secound parameter is key (42FA)
paramenters are any 4 hex numbers (16 bit)
The result is FEAC

### 3- Decrypt the Output using this command

```bash
main.exe DEC FEAC 42FA
```

- the first paramenter is Data (FEAC) and the secound paramenter is key (42FA)

- the parameters are any 16-bit hex number
  and the output will be the orignal Data (6DF4)

## Features

<ul>
    <li><strong>Lightweight Implementation:</strong> A simplified version of AES for educational purposes.</li>
    <li><strong>Encryption and Decryption:</strong> Supports both operations with a given key and plaintext/ciphertext.</li>
    <li><strong>Command-Line Interface:</strong> Run operations with simple command-line arguments.</li>
</ul>

---

## Tech Stack

<p><strong>Languages & Tools:</strong></p>
<ul>
    <li><a href="https://en.cppreference.com/w/c">C Programming Language</a></li>
    <li>Standard C libraries for input/output and cryptographic logic.</li>
</ul>

---

## Installation

### Prerequisites

- GCC or any compatible C compiler installed on your machine.
- A terminal or command prompt to run the program.

### Steps

1. Clone the repository:
   
   ```bash
   git clone https://github.com/AhmedEmadh/all_projects/tree/master/C%20Projects/Simplified%20Advanced%20Encryption%20Standard
   ```
