# Bank Management System

<p align="center"><strong>A comprehensive C++ project for managing bank clients, user roles, and banking operations in a streamlined and secure manner.</strong></p>

---

## Table of Contents

- [About the Project](#about-the-project)
- [Features](#features)
- [Tech Stack](#tech-stack)
- [Installation](#installation)
- [Screenshots](#screenshots)
- [Usage](#usage)
- [Modules Overview](#modules-overview)
- [Future Enhancements](#future-enhancements)

---

## About the Project

The **Bank Management System** is a full-featured application designed to manage banking operations, including client data, transactions, and user management. It supports the following functionalities:

- Adding, updating, and deleting clients and users.
- Handling bank transactions such as deposits and withdrawals.
- Providing a secure system with role-based permissions.
- Displaying detailed client and user lists.

This project is an excellent demonstration of C++ concepts such as:

- Object-Oriented Programming (OOP).
- File I/O for data persistence.
- Data validation and error handling.
- Modular design for maintainability.

---

## Features

- **Client Management**:
  
  - Add, update, and delete clients.
  - View detailed client information.
  - Check account balances and transaction history.

- **Transaction Management**:
  
  - Perform deposits and withdrawals.
  - Display transaction summaries.

- **User Management**:
  
  - Role-based user access and permissions.
  - Add, update, and delete user accounts.
  - Manage user permissions for secure operations.

- **Authentication**:
  
  - Secure login system with username and password validation.
  - Lockout mechanism after multiple failed attempts.

- **Data Persistence**:
  
  - All client and user data stored in text files.
  - Persistent storage ensures data retention between sessions.

---

## Tech Stack

- **Programming Language**: C++.
- **Libraries Used**:
  - Standard Template Library (STL) for data structures such as `vector`, `map`, and `queue`.
  - `<fstream>` for file handling.
  - `<iomanip>` for formatted output.

---

## Installation

### Prerequisites

- A C++ compiler (e.g., GCC, Clang, or MSVC).
- A terminal or IDE (e.g., Visual Studio, VSCode, or CLion).

### Steps

1. Clone the repository:
   
   ```bash
   git clone https://github.com/AhmedEmadh/all_projects System.git
   ```

2. Navigate to the project folder:
   
   ```bash
   cd Bank-Management-System
   ```

3. Compile the project:

```bash
g++ *.cpp -o BankSystem
```

Run the application:

```bash
./BankSystem
```

## Screenshots

![MainMenu Screenshot](https://github.com/AhmedEmadh/all_projects/blob/master/C%2B%2B%20Projects/Bank_System_UI/Main%20menu.png)
![Client List Screenshot](https://github.com/AhmedEmadh/all_projects/blob/master/C%2B%2B%20Projects/Bank_System_UI/Client_List.png)
![Manage Users Screenshot](https://github.com/AhmedEmadh/all_projects/blob/master/C%2B%2B%20Projects/Bank_System_UI/Manage%20Users.png)
![User_List Screenshot](https://github.com/AhmedEmadh/all_projects/blob/master/C%2B%2B%20Projects/Bank_System_UI/User_List.png)

## Usage

1. **Login**:
   
   - Enter your username and password to access the system.
   - Admins and users with permissions can access specific features.

2. **Main Menu**:
   
   - Perform various actions such as managing clients, transactions, and users.

3. **Client Management**:
   
   - Add, update, and delete client details.

4. **Transactions**:
   
   - Deposit or withdraw funds.
   - View updated account balances.

5. **User Management**:
   
   - Add, update, or delete users with specific roles and permissions.

---

## Modules Overview

### 1. **Client Management**

- Files: `clsAddNewClientScreen.h`, `clsDeleteClientScreen.h`, `clsUpdateClientScreen.h`, `clsFindClientScreen.h`.
- Key Features:
  - Add new clients with account details.
  - Edit or delete existing client information.
  - Search for clients by account number.

### 2. **Transaction Management**

- File: `clsDepositScreen.h`.
- Key Features:
  - Deposit funds into client accounts.
  - Display updated balances.

### 3. **User Management**

- Files: `clsAddNewUserScreen.h`, `clsDeleteUserScreen.h`, `clsUpdateUserScreen.h`, `clsFindUserScreen.h`.
- Key Features:
  - Create and manage user accounts.
  - Assign role-based permissions for secure access.

### 4. **Authentication**

- File: `clsLoginScreen.h`.
- Key Features:
  - Secure login mechanism.
  - Lockout system after multiple failed login attempts.

### 5. **Main Menu**

- File: `clsMainScreen.h`.
- Key Features:
  - Central hub to navigate between system features.

## Future Enhancements

- **Database Integration**:
  
  - Transition from file-based storage to SQL or NoSQL databases for improved scalability.

- **Graphical User Interface (GUI)**:
  
  - Develop a GUI to make the system more user-friendly.

- **Enhanced Security**:
  
  - Implement encryption for stored passwords and secure communication protocols.

- **Multi-Branch Support**:
  
  - Allow managing clients across multiple branches.
