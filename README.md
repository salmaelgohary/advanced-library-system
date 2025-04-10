# Advanced Library Management System

This project is a C++ based Library System designed to manage books, users, and their interactions through a simple yet effective interface. This project showcases object-oriented programming concepts like inheritance and encapsulation, and serves as a strong foundation for expanding into a more feature-rich library management tool.

---

## Features & Structure

### `Book` Class  
Represents individual books in the library, storing details such as:
- Title  
- Author  
- Genre  
- Year of publication

### `Library` Class  
Manages the library's book collection, with functionality to:
- Add new books  
- Remove existing ones  
- Search for specific titles

### `LibraryUser` Class  
A base class representing a general library user. Stores:
- User name  
- Unique user ID

### `Teacher` Class *(inherits from `LibraryUser`)*  
Represents teachers using the system. Includes attributes and methods specific to teachers.

### `Student` Class *(inherits from `LibraryUser`)*  
Represents students using the system. Includes attributes and methods specific to students.

### `main.cpp` (Driver Code)  
Acts as the entry point and user interface for the program. Enables interaction with the system’s classes and methods.

---

## How to Run the Program

> Make sure all required `.cpp` and `.hpp` files are in the same directory.

### 1. Compile the Code
Using `g++` or any modern C++ compiler:
```bash
g++ -std=c++11 main.cpp book.cpp library.cpp libraryuser.cpp student.cpp teacher.cpp -o library-system
```

### 2. Run the Executable
```bash
./library-system
```
