#include <iostream>
#include "book.hpp" //include header file
using namespace std;

Book::Book(): 
    book_title("N/A"), authors("N/A"), genre("N/A"), date_of_publication ("N/A") {}

Book::Book(string input_title): 
    book_title(input_title), authors("N/A"), genre("N/A"), date_of_publication ("N/A") {}

Book::Book(string input_title, string input_authors): 
    book_title(input_title), authors(input_authors), genre("N/A"), date_of_publication ("N/A") {}

Book::Book(string input_title, string input_authors, string input_genre): 
    book_title(input_title), authors(input_authors), genre(input_genre), date_of_publication ("N/A") {}

Book::Book(string input_title, string input_authors, string input_genre, string input_dop): 
    book_title(input_title), authors(input_authors), genre(input_genre), date_of_publication (input_dop) {}



string Book::get_title(){
    return book_title;
}
string Book::get_authors(){
    return authors;
}
string Book::get_genre(){
    return genre;
}
string Book::get_dop(){
    return date_of_publication;
}

void Book::set_authors(string new_authors){
    authors = new_authors;
}
void Book::set_genre(string new_genre){
    genre = new_genre;
}
void Book::set_dop(string new_dop){
    date_of_publication = new_dop;
}

bool Book::operator==(const Book& input_book) const{
    bool are_equal;
    
    //check if all attributes of current book and input book are equal
    are_equal = (book_title == input_book.book_title) && 
        (authors == input_book.authors) && 
        (genre == input_book.genre) && 
        (date_of_publication == input_book.date_of_publication);
    return are_equal;
}
void Book::print(){
    cout << "Title of book: " << book_title << endl;
    cout << "Authors: " << authors << endl;
    cout << "Date of Publication: " << date_of_publication << endl << endl;
}