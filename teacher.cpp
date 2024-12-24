#include <iostream>
#include <string>
#include "libraryuser.hpp"
#include "teacher.hpp"
#include "library.hpp"
#include "book.hpp"

using namespace std;

Teacher::Teacher() : LibraryUser(), borrow_limit(5) {} //set default values

Teacher::Teacher(string name, int user_id, int borrowed_count, int limit) : LibraryUser(name, user_id, borrowed_count), borrow_limit(limit){}

int Teacher::get_borrow_limit(){
    return borrow_limit;
}

vector <string> Teacher:: get_genres(){
    return valid_genres;
}

void Teacher::add_book_to_library(Library& library, Book* book){
    library.insert_books(book); //uses insert books method on the library they want to insert the book into
}

void Teacher::update_book_details(Library& library, string title, string new_authors, string new_genre, string new_dop){
    
    Book* book = library.find_book_by_title(title); //creates a pointer to a book in the library that has the same title they're searching for 

    if (book == nullptr){ //if no book was found
        cout << "Cannot update book details, this book does not exist in the library!" << endl;
    }
    else{
        book -> set_authors(new_authors); // set all the attributes to the desired attributes of the teacher
        book -> set_genre(new_genre);
        book -> set_dop(new_dop);
        cout << "Book details updated for " << title << endl;
    }

}
void Teacher::print(){
    cout << "This user is a Teacher: " << endl; //specifies type of user
    LibraryUser::print_user(); //calls LibraryUser print to print inherited attributes
    cout << "User borrow limit: " << borrow_limit << endl;
    cout << "Valid genres for user: ";
    
    for(int i=0; i < valid_genres.size(); i++){
        cout << valid_genres[i] << ", ";
    }
    cout << endl;
}