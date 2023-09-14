# Library Management System

## Description

This is a simple Library Management System implemented in C. It allows you to manage books and student records in a library. You can add new books, issue books to students, return books, display student details, and list available books in the library.

## Table of Contents

- [Features](#features)
- [Usage](#usage)
- [Functions](#functions)
- [Contributing](#contributing)


## Features

- **Add New Book:** You can add new books to the library by providing the book's title, author, and ID.

- **List Books:** View a list of all the books available in the library.

- **Issue Books:** Issue a book to a student by specifying the book's ID. You'll need to enter the student's name and email address.

- **Return Books:** Return a book to the library. This will remove the book from the student's records and add it back to the available books.

- **Display Student Details:** View a list of students who have borrowed books from the library, along with their book details.

## Usage

1. Clone this repository to your local machine.

2. Compile the code using a C compiler.

3. Run the compiled executable.

4. Follow the on-screen menu to perform various library management tasks.

## Functions

### `add_new()`

This function allows you to add a new book to the library by providing the book's title, author, and ID.

### `ListBook()`

List all the books available in the library.

### `IssueBook()`

Issue a book to a student by specifying the book's ID. You'll need to enter the student's name and email address.

### `BookReturn()`

Return a book to the library. This function removes the book from the student's records and adds it back to the available books.

### `display()`

Display a list of students who have borrowed books from the library, along with their book details.

### `main()`

The main function provides a menu for interacting with the Library Management System. You can choose options to add new books, issue books, return books, display student details, list books, or exit the program.

## Contributing

Feel free to contribute to this project by submitting bug reports or feature requests. If you'd like to contribute code, please fork the repository, make your changes, and submit a pull request.

