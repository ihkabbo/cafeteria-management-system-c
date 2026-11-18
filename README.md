# 🍽️ Cafeteria Management System (C)

## 📌 Overview

The Cafeteria Management System is a console-based application developed using the C programming language.

The system is designed to manage cafeteria food items, student interactions, and order processing. It uses fundamental data structures such as Linked Lists, Stacks, and Queues, along with file handling to store and retrieve information.

It provides separate functionalities for administrators and students.

## ✨ Features

### 👨‍💼 Admin Module
- Admin registration and login
- Add food items to the menu
- View available food items
- Delete food items
- View customer orders
- Serve orders

### 🎓 Student Module
- Student registration and login
- View food menus
- Select food categories
- Add items to cart
- Undo the last cart action
- Remove items from cart
- View cart and calculate total price
- Place food orders

## 🛠️ Technologies Used

- **Programming Language:** C
- **Data Structures:** Linked List, Stack, Queue
- **File Handling:** Text file storage
- **Development Environment:** CodeBlocks
- **Operating System:** Windows

## 🧠 Data Structures Implemented

### 1. Linked List
Used to manage food items dynamically in three categories:
- Breakfast
- Lunch
- Snacks

### 2. Stack
Used to implement the shopping cart. Items are added using the Push operation and the last added item can be removed using the Pop operation.

### 3. Queue
Used to manage customer orders following the First-In-First-Out (FIFO) principle.

## 💾 File Handling

The system uses text files to store and retrieve information, including:

- Food menu data
- Admin credentials
- Student credentials
- Order history

This allows important information to remain available between program executions.

## ⚙️ How the System Works

1. The program loads available food menu data from files.
2. Users can register or log in as an administrator or student.
3. Administrators manage food items and process orders.
4. Students browse menus and add food items to their carts.
5. Students place orders after reviewing their cart.
6. Orders are added to a queue.
7. Administrators serve orders in sequence.

## ▶️ How to Run

1. Download or clone this repository.
2. Open the C source file using CodeBlocks or another C compiler.
3. Compile and run the program.
4. Register as an administrator or student to access the system.

## 📂 Project Files

- [C Source Code](./cafeteria-management-system.c)
- [Project Report (PDF)](./cafeteria-management-system_Report.pdf)

## 🎯 Learning Objectives

- Understand practical applications of data structures.
- Implement linked lists, stacks, and queues in C.
- Apply file handling for data storage.
- Develop a menu-driven application.
- Understand basic order management operations.

## 🔮 Future Improvements

- Add a graphical user interface (GUI).
- Improve input validation.
- Implement a real-time database.
- Add search and edit features.

## 👨‍💻 Author

**Md. Imran Hossen**
