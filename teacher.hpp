#ifndef TEACHER_HPP

#define TEACHER_HPP

#include <string>
#include <vector>
#include <iostream>
#include "libraryuser.hpp"
#include "teacher.hpp"
#include "book.hpp"

using namespace std;

class Library;

class Teacher : public LibraryUser{ 
    int borrow_limit;
    vector<string> valid_genres = {"Education", "Comedy", "Science"};

    public:
    Teacher(); //Default constructor

    Teacher(string name, int user_id, int borrowed_count, int limit); //parametrized constructor

    int get_borrow_limit();
    //PURPOSE: Get access to borrowing limit
    //INPUT: None
    //OUTPUT: the borrowing limit

    vector <string> get_genres();
    //PURPOSE: Get access to valid genres for this user
    //INPUT: None
    //OUTPUT: the valid genres in a vector

    void add_book_to_library(Library& library, Book* book);
    //PURPOSE: allows a teacher user to add a book to the library
    //INPUT: the library they want to input into and the pointer to the book they want inserted
    //OUTPUT: None

    void update_book_details(Library& library, string title, string new_authors, string new_genre, string new_dop);
    //PURPOSE: update specific attributes of a book in the library 
    //INPUT: the library they're searching in and the new updates they want to make to authors, genre, and dop
    //OUTPUT: None

    void print();
    //PURPOSE: print out all the details about a student user
    //INPUT: None
    //OUTPUT: None
};

#endif