# Address Book Project

<p align="center"><strong>A simple address book application that allows users to store, retrieve, and manage contacts using C++ and file I/O operations.</strong></p>

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

This **Address Book** is a console-based application built in C++ to manage contacts. It allows users to:

- Add contacts (name and phone number) to the address book.
- Retrieve a contact's phone number by entering the name.
- Remove a contact or clear all contacts in the address book.
- Store the address book data persistently in a file.

The application demonstrates file operations (`fstream`), data management using `std::map`, and offers basic functionality like add, remove, and display contacts.

---

## Features

- **Add Contacts**: Allows users to add new contacts with a name and phone number.
- **Retrieve Contact**: Fetches a contact's phone number by the contact's name.
- **Remove Contacts**: Allows removal of specific contacts or all contacts.
- **Persistent Storage**: Data is stored in a file (`database.db`) to persist even after the program is closed.
- **Simple CLI Interface**: Interact with the program using simple text commands.

---

## Tech Stack

<p><strong>Languages & Tools:</strong></p>
<ul>
    <li><a href="https://en.cppreference.com/w/cpp">C++ Programming Language</a></li>
    <li>File I/O using <code>std::fstream</code></li>
    <li>Standard C++ libraries for input/output and data management.</li>
</ul>

---

## Installation

### Prerequisites

- A C++ compiler (such as GCC or Clang) installed on your machine.
- A terminal or command prompt to compile and run the program.

### Steps

1. Clone the repository:
   
   ```bash
   git clone https://github.com/yourusername/address-book.git
   ```

2. Navigate to the project directory:
   
   ```bash
   cd address-book
   ```

3. Compile the code:
   
   ```bash
   g++ main.cpp -o addressbook
   ```

4. Run the program:
   
   ```bash
   ./addressbook
   ```

### Usage

Once the program is running, you will be prompted to choose an operation. Here’s a list of available commands:

- **1**: Add a new contact (Name and Number).
- **2**: Retrieve a contact’s phone number.
- **3**: Show all contacts in the address book.
- **4**: Remove a specific contact by name.
- **5**: Remove all contacts from the address book.
- **0**: Exit the program.

You will interact with the program using simple numeric input to select the operation, and text input to enter names and numbers.

---

## Screenshot

![](https://github.com/AhmedEmadh/all_projects/blob/master/C%2B%2B%20Projects/Address_Book/Screenshot.png)



---

## Example Code

```
What do you want to do (1:Add,2:get number,3:show all,4:remove,5:to remove all,0:to End): 1
Enter Name to add: John
Enter number to add: 123456789

What do you want to do (1:Add,2:get number,3:show all,4:remove,5:to remove all,0:to End): 2
Enter the name to get the number: John
The number is: 123456789

What do you want to do (1:Add,2:get number,3:show all,4:remove,5:to remove all,0:to End): 3
Showing all the data:
Name: John
Number: 123456789

What do you want to do (1:Add,2:get number,3:show all,4:remove,5:to remove all,0:to End): 4
Enter Name to remove: John

What do you want to do (1:Add,2:get number,3:show all,4:remove,5:to remove all,0:to End): 0
```
