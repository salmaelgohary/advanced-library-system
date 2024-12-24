#ifndef BOOK_HPP

#define BOOK_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
    string book_title, authors, genre, date_of_publication;

    public: 
    Book(); 
    //default constructor with no parameters that sets all three attributes to “n/a”
    Book(string input_title); 
    // constructor where only the title is provided and the other two attributes are set to “n/a”    
    Book(string input_title, string input_authors); 
    //constructor where only the title and authors are provided and the date of publication is set to “n/a
    Book(string input_title, string input_authors, string input_genre); 
    // constructor where all three attributes are inputted (i.e., the title, authors, and date of publication)
    Book(string input_title, string input_authors, string input_genre, string input_dop);

    string get_title();
    //PURPOSE: Get function to access title of the book
    //INPUT: None
    //OUTPUT: Title of the book

    string get_authors();
    //PURPOSE: Get function to access authors of the book
    //INPUT: None
    //OUTPUT: Authors of the book  

    string get_genre();
    //PURPOSE: Get function to access genre of the book
    //INPUT: None
    //OUTPUT: genre of the book  

    string get_dop();
    //PURPOSE: Get function to access date of publication of the book
    //INPUT: None
    //OUTPUT: Date of publication of the book  

    void set_authors(string new_authors);
    //PURPOSE: set new authors to a book 
    //INPUT: string of new author names
    //OUTPUT: none

    void set_genre(string new_genre);
    //PURPOSE: set new genre to a book 
    //INPUT: string of new genre name
    //OUTPUT: none

    void set_dop(string new_dop);
    //PURPOSE: set new date of publication to a book 
    //INPUT: string of the new date of publication
    //OUTPUT: none

    bool operator==(const Book& input_book) const;
    //PURPOSE: Check if two books are the same 
    //INPUT: Comparison book
    //OUTPUT: True if books are the same, false if books are different

    void print();
    //PURPOSE: Print book information, including authors, title and date of publication 
    //INPUT: None
    //OUTPUT: none
};

#endif