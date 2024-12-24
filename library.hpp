#ifndef LIBRARY_HPP

#define LIBRARY_HPP

#include "book.hpp"
#include "student.hpp"
#include "teacher.hpp"
#include "libraryuser.hpp"

#include <iostream>
#include <string>
using namespace std;

class Teacher;

class Library{
    vector<Book*> book_list;
    vector<bool> is_borrowed;

    public:
    Library();
    //default constructor to initialize book list attribute to empty vector (empty library)
    Library(vector<Book*> input_vector);
    //paramaterized constructor to initialize stores the Book values from input vector into the book list attribute

    bool insert_books(Book* input_book); 
    //PURPOSE: Insert books into the library but first check if inputted book already exists in the library
    //INPUT: Input book to insert (Book instance passed in by value) 
    //OUTPUT: true if book is inserted, false if book is rejected  

    bool insert_books(string title = "N/A", string authors = "N/A", string genre = "N/A", string dop = "N/A");
    //PURPOSE: Insert books into the library but first check if inputted book already exists in the library
    //INPUT: String of title, author and date of publication of input book 
    //OUTPUT: true if book is inserted, false if book is rejected 

    bool remove_books(Book* input_book); 
    //PURPOSE: Remove books from the library but first check if inputted book exists in the library to be      removed
    //INPUT: Input book to remove (of type book) 
    //OUTPUT: True if removal succeeds, false if removal rejected 
    
    bool remove_books(string title = "N/A", string authors = "N/A", string genre = "N/A", string dop = "N/A");
    //PURPOSE: Remove books from the library but first check if inputted book exists in the library to be removed
    //INPUT: String of title, author and date of publication of input book 
    //OUTPUT: True if removal succeeds, false if removal is rejected 

    void advanced_search(string title_input = "", string author_input = "", string genre_input = "");
    //PURPOSE: Search for a book in the library based on substrings of attributes
    //INPUT: Title, author and genre substrings (can input one, two or all of parameters)
    //OUTPUT: none
    
    void borrow_book(Student& user, string title, string genre);
    //PURPOSE: Allows student to borrow a book with the desired title from library and checks if the genre of that book is acceptable for them to borrow 
    //INPUT: student that will borrow the book, title of book to borrow, and genre of book to borrow
    //OUTPUT: none
    
    void borrow_book(Teacher& user, string title, string genre);
    //PURPOSE: Allows teacher to borrow a book with the desired title from library and checks if the genre of that book is acceptable for them to borrow 
    //INPUT: teacher that will borrow the book, title of book to borrow, and genre of book to borrow
    //OUTPUT: none

    void return_book(LibraryUser& user, string title);
    //PURPOSE: allows a user to return a book to the library, checks if book is actually borrowed to be returned and updates the status of that book to not borrowed when return succeeds
    //INPUT: user (either student or teacher) that is returning the book and title of book to return
    //OUTPUT: none

    void print(); 
    //PURPOSE: Print a list of the books stored in the library 
    //INPUT: None
    //OUTPUT: Printed list of the books stored in the library

    Book* find_book_by_title(string title); 
    //PURPOSE: Find a book in the library only by its title 
    //INPUT: title of book to be found in the library
    //OUTPUT: pointer to the book with the found title

};

#endif