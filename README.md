# Cafeteria Management System

A C-based Cafeteria Management System that manages food menus, student accounts, shopping carts, and order processing using fundamental data structures.

## Project Overview

This project is developed using the C programming language as part of the Data Structure Lab (CSE-206) course.

The system simulates a cafeteria environment with two types of users: administrators and students.

It uses Linked Lists to manage food items, Stacks to implement the shopping cart, and Queues to process customer orders. File handling is also used to store menu information, user credentials, and order history.

## Features

- Separate admin and student modules.
- Admin registration and login.
- Student registration and login.
- Add food items to different categories.
- View available food items.
- Delete food items from the menu.
- Manage three food categories: Breakfast, Lunch, and Snacks.
- Add food items to a shopping cart.
- Undo the last cart action.
- Remove specific items from the cart.
- View cart items and calculate the total price.
- Place food orders.
- View pending customer orders.
- Serve orders in FIFO order.
- Store and retrieve information using text files.

## User Modules

### Admin Module

- Register and log in as an administrator.
- Add food items with quantity and price.
- View food menus.
- Delete food items.
- View customer orders.
- Serve customer orders.

### Student Module

- Register and log in as a student.
- View available food menus.
- Select food items from different categories.
- Add items to the shopping cart.
- Undo the last cart action.
- Remove specific items from the cart.
- View cart details and calculate the total price.
- Place food orders.

## Food Categories

| Category | Description |
|---|---|
| Breakfast | Manages breakfast items |
| Lunch | Manages lunch items |
| Snacks | Manages snacks |

## Data Structures Implemented

| Data Structure | Application |
|---|---|
| Linked List | Dynamically manages food items in different categories |
| Stack | Implements shopping cart operations using LIFO |
| Queue | Processes customer orders using FIFO |

### Linked List

Linked Lists are used to store and manage food items dynamically. Separate linked lists are maintained for Breakfast, Lunch, and Snacks.

### Stack

A Stack is used to implement the shopping cart. Items are added using the Push operation, and the last added item can be removed using the Pop operation.

### Queue

A Queue is used to manage customer orders. Orders are added using Enqueue and served using Dequeue, following the First-In-First-Out (FIFO) principle.

## Software and Technologies

- Programming Language: C
- Data Structures: Linked List, Stack, Queue
- File Handling: Text file storage
- Compiler: CodeBlocks
- Operating System: Windows

## File Handling

The system uses text files to store and retrieve information:

- `breakfast.txt` – Breakfast menu data.
- `lunch.txt` – Lunch menu data.
- `snacks.txt` – Snacks menu data.
- `admin.txt` – Administrator credentials.
- `student.txt` – Student credentials.
- `orders.txt` – Order history.

This allows menu information and other records to be stored between program executions.

## How It Works

1. The program loads the food menus from text files.
2. Users can register or log in as administrators or students.
3. Administrators can add, view, and delete food items.
4. Students can browse the available food menus.
5. Students can add food items to their shopping carts.
6. The Stack manages cart operations.
7. Students can review their carts and place orders.
8. Orders are added to a Queue.
9. Administrators can view and serve orders in FIFO order.
10. Menu and order information is stored using file handling.

## Testing

The project was tested using different operations:

- **Admin Access:** Tested adding and deleting food items, viewing menus, and managing orders.
- **Student Access:** Tested viewing menus and adding or removing items from the cart.
- **Order Processing:** Tested placing and serving orders.
- **File Handling:** Verified menu updates and stored information.

The project report describes successful execution of the major operations and FIFO-based order processing.

## Limitations

- Does not support multi-word food item names.
- Stock is not fully restored when removing items from the cart.
- Limited input validation in some operations.

## Future Improvements

- Develop a graphical user interface (GUI).
- Improve input validation.
- Implement a real-time database.
- Add search and edit features.
- Improve stock synchronization.

## Project Files

- [C Source Code](./cafeteria-management-system.c) – Complete C implementation of the cafeteria management system.
- [Project Report (PDF)](./cafeteria-management-system_Report.pdf) – Data Structure Lab project documentation.

## Author

**Developed by:** Ihkabbo

Academic project focused on C programming, linked lists, stacks, queues, file handling, and practical applications of data structures.
