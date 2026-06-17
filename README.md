# Book Management System

A robust C++ console application designed to manage a library collection. This project demonstrates advanced Object-Oriented Programming (OOP) concepts, manual memory management, and modern C++ features.

## Features
* **OOP Principles:** Implementation of inheritance (PictureBook inheriting from Book) and polymorphism.
* **Manual Memory Management:** Full implementation of the "Rule of 5" in the `Magazine` class to ensure safe memory handling.
* **Error Handling:** Custom exception class `InvalidBookException` to handle invalid data inputs.
* **Resource Management:** Custom `FileHandler` class for robust file I/O operations with manual buffer management.
* **Modern C++:**
    * Use of `std::shared_ptr` for efficient memory management of magazine objects.
    * Use of Lambda expressions for filtering and deleting elements in vectors.
    * Use of STL containers (`std::vector`).

## Class Overview
* **`Book`**: Base class representing a book with common attributes (name, author, year, category, level).
* **`PictureBook`**: Inherits from `Book`, adding specialized fields (illustrator, drawing type) and overriding the display function.
* **`Magazine`**: Manages magazines, including dynamic arrays for publishing partners and strict memory management.
* **`InvalidBookException`**: A custom exception for input validation.
* **`FileHandler`**: Manages file operations and memory buffers for data persistence.
* **`Library`**: The core controller managing collections of books and magazines.

## Technologies Used
* **Language:** C++
* **Environment:** Visual Studio
* **Standard Library:** STL (Vector, Memory, String, Fstream)

## How to Run
1. Ensure you have a C++ compiler (C++11 or higher).
2. Open the `.sln` file in Visual Studio.
3. Build and execute the project.

---
*Developed as part of an advanced C++ programming coursework.*
