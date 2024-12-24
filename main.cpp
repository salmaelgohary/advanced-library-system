#include "library.hpp"
#include "book.hpp"
#include "libraryuser.hpp"
#include "student.hpp"
#include "teacher.hpp"

#include <iostream>
using namespace std;

int main(){
    //testing a constructor and print method for Book object
    Book b1("Harry Potter", "J.K. Rowling", "Fantasy");
    cout << "Printing Book information: " << endl;
    b1.print();

    //create a vector of book pointers
    vector <Book*> book_ptr;
    book_ptr.push_back(new Book(b1));
    book_ptr.push_back(new Book("Happy Days", "J.Frank"));
    book_ptr.push_back(new Book("Live Life", "Annie", "Romance", "2012"));
    book_ptr.push_back(new Book("Babies Born"));

    //pass the created books into a Library and test two constructors for Library
    Library library(book_ptr);
    Library library2;

    //testing printing methods on both libraries
    cout << "Printing Library information: " << endl;
    cout << "Library 2: " << endl; 
    library2.print(); //testing print method on empty library, should say it is empty
    
    cout << "Library 1: " << endl;
    library.print(); //testing print method on initialized library, should print out all book details

    //tests for successful insertion by inserting books not yet in library
    cout << "Lets add some books to the library!" << endl;
    library.insert_books(new Book("Lively"));
    library.insert_books(new Book("Physics", "Thomas Willet", "Science", "2020"));
    library.insert_books(new Book("Math", "Speziale", "Calculus", "2000"));
    library.insert_books(new Book("Work Balance", "Robert", "Science"));
    library.insert_books(new Book("Lively", "Marcus"));
    library.insert_books("Holidays", "Johnny", "Romance", "1994");
    library.insert_books("Coding", "Fani", "Education", "2024");

    cout << endl;
    cout << endl;

    //test for unsuccessful insertion
    cout << "Lets try to add books already existing in Library!" << endl;
    library.insert_books("Physics", "Thomas Willet", "Science", "2020");
    library.insert_books(new Book("Live Life", "Annie", "Romance", "2012"));

    cout << endl;
    cout << endl;
    
    //successful removal
    cout << "Lets remove some books!" << endl;    
    library.remove_books("Work Balance", "Robert", "Science"); 
    library.remove_books(new Book("Math", "Speziale", "Calculus", "2000"));

    cout << endl;
    cout << endl; 

    //unsuccessful removal
    cout << "Lets try removing nonexistent books from Library!" << endl;
    library.remove_books("Make Cookies");
    library.remove_books(new Book("Divergent", "John Legend", "Action", "2009"));
    
    cout << endl;
    cout << endl; 
    
    //declare a student and a teacher
    cout << "Lets create some students and teachers!" << endl;
    Student arwa("Arwa", 21143658, 0, 1, 5);
    arwa.print();

    cout << endl;

    Student salma("Salma", 21123164, 0, 2, 1);
    salma.print();

    cout << endl;

    Teacher fani("Professor Fani", 123456, 0, 10);
    fani.print();

    cout << endl;
    cout << endl; 

    //testing for student 1 (arwa) 
    cout << "Arwa is testing some methods in the Library!\n" << endl;
    cout << "Arwa is trying to borrow Coding." << endl;
    library.borrow_book(arwa, "Coding", "Education"); //borrowing a book that student is not allowed to borrow
    cout << "Now, Arwa is trying to borrow Holidays." << endl;
    library.borrow_book(arwa, "Holidays", "Romance"); //borrowing a valid book
    cout << arwa.get_name() << "'s borrowed count: " << arwa.get_borrowed_count() << endl; //checking to see if student's borrowed count increased by 1
    library.return_book(arwa, "Holidays");
    cout << arwa.get_name() << "'s new borrowed count: " << arwa.get_borrowed_count() << endl; //checking to see if student's borrowed count decreased by 1

    cout << endl;
    cout << endl; 

    //testing for student 2 (salma)
    cout << "Salma is also testing some methods in the Library!\n" << endl;
    cout << "Salma is trying to borrow Live Life." << endl;
    library.borrow_book(salma, "Live Life", "Romance"); //borrowing an acceptable book for student
    cout << salma.get_name() << "'s borrowed count: " << salma.get_borrowed_count() << endl; // should print 1
    cout << "Salma is trying to also borrow Harry Potter." << endl;
    library.borrow_book(salma, "Harry Potter", "Fantasy"); //should throw error since borrow limit is already met
    //now try to make borrow limit 1 again by returning a book.
    library.return_book(salma, "Live Life");
    cout << salma.get_name() << "'s new borrowed count: " << salma.get_borrowed_count() << endl; //should now print 0
    cout << "Now Salma can borrow Harry Pottter!" << endl;
    library.borrow_book(salma, "Harry Potter", "Fantasy"); //should work

    cout << endl;
    cout << endl; 

    //testing for teacher 1 (fani) 
    cout << "Professor Fani is testing out some methods!\n" << endl;
    cout << "Professor is trying to borrow Coding" << endl;
    library.borrow_book(fani, "Coding", "Education"); //borrowing acceptable book for teacher
    cout << "Now the professor is trying to borrow Holidays" << endl;
    library.borrow_book(fani, "Holidays", "Romance"); //borrowing a book teacher is not allowed to borrow
    cout << fani.get_name() << "'s borrowed count: " << fani.get_borrowed_count() << endl; //checking to see if teacher's borrowed count increased by 1
    library.return_book(fani, "Coding");
    cout << fani.get_name() << "'s new borrowed count: " << fani.get_borrowed_count() << endl; //checking to see if teacher's borrowed count decreased by 1 again

    cout << endl;

    //testing successful teacher adding book to library
    cout << "Professor Fani is editing the Library!\n" << endl;

    cout << "Professor is adding a book to the library." << endl;
    fani.add_book_to_library(library, new Book("Twinkle Twinkle Little Star", "Arwa", "Lullaby", "1980"));

    //testing unsuccessful teacher adding book to library
    cout << "Professor is adding an already existing book to the library." << endl;
    fani.add_book_to_library(library, new Book("Physics", "Thomas Willet", "Science", "2020"));

    //testing successful teacher updating book details
    cout << "Professor is updating a book in the library." << endl;
    fani.update_book_details(library, "Twinkle Twinkle Little Star", "Da Vinci", "Nursery", "1999");
    
    //testing unsuccessful teacher updating book details
    cout << "Professor is updating a nonexistent book in the library." << endl;
    fani.update_book_details(library, "My boy", "Rob", "Nursery", "1999");


    cout << endl;
    cout << endl; 

    //Test advanced search
    cout << "Lets search for some books in the Library!\n" << endl;
    library.advanced_search("Lively", "Marcus");
    library.advanced_search("Physics");
    library.advanced_search("Twinkle Twinkle Little Star", "Arwa", "Lullaby");

    library.advanced_search("Twinkle Twinkle Little Star", "Da Vinci", "Nursery");
    library.advanced_search("Salma's Diary", "", "2012");
    
    return 0;
}