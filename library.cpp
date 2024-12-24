#include "library.hpp"
#include "book.hpp"
#include "student.hpp"
#include "teacher.hpp"
#include "libraryuser.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

Library::Library() { // default constructor, set to empty vector
  vector<Book*> book_list;
  vector<bool> is_borrowed;
}

Library::Library(vector<Book*> input_vector) : book_list(input_vector) {
  is_borrowed.resize(book_list.size(), false); //resize the is_borrowed vector to have same size as library vector
}

bool Library::insert_books(Book *input_book) {
  for (int i = 0; i < book_list.size(); i++) { 
    if (*(input_book) == *(book_list[i])) {// check if input book is already in library
      cout << "Insertion Rejected! " << input_book->get_title() << " is already in the library!\n" << endl; // if duplicate book found, reject the insertion
      delete input_book; //delete the pointer made for input_book
      input_book = nullptr;
      return false;
    }
  }
  // if no duplicate book found, add book into library
  cout << input_book->get_title() << " inserted successfully!\n" << endl;
  book_list.push_back(input_book);

  is_borrowed.resize(book_list.size()); // resize the is_borrowed vector to mimic new book list size
  is_borrowed[book_list.size() - 1] = false; // for the book just added, make sure its value in is_borrowed vector is false

  return true; // return true if insertion succeeds
}

bool Library::insert_books(string title, string authors, string genre, string dop) { //same as above but with provided attributes
  Book *input_ptr = new Book(title, authors, genre, dop); //create a pointer with provided attributes

  for (int i = 0; i < book_list.size(); i++) { // check if input book is already in library
    if (*(input_ptr) == *(book_list[i])) {
      cout << "Insertion Rejected! " << input_ptr->get_title() << " is already in the library!\n" << endl; // if duplicate book found, reject the insertion
      delete input_ptr;
      input_ptr = nullptr;
      return false;
    }
  }
  // if no duplicate book found, add book into library
  cout << input_ptr->get_title() << " inserted successfully!\n" << endl;
  book_list.push_back(input_ptr);

  is_borrowed.resize(book_list.size()); // resize the is_borrowed vector to mimic new book list size
  is_borrowed[book_list.size() - 1] = false; // for the book just added, make sure its value in is_borrowed vector is false

  return true; // return true if insertion succeeds
}

bool Library::remove_books(Book *input_book) {
  for (int i = 0; i < book_list.size();
       i++) { // check if the input book exists in the library
    if (*(input_book) == *(book_list[i])) {
      cout << "Removing " << input_book->get_title() << "...\n" << endl;
      delete book_list[i]; //delete the pointer to that book
      book_list.erase(book_list.begin() + i);
      is_borrowed.erase(is_borrowed.begin() + i);
      return true;
    }
  }
  // if input book is not found in the library, reject the removal
  cout << "Removal Rejected! " << input_book->get_title() << " is not in the library!\n" << endl;
  delete input_book; //delete the pointer that was created
  input_book = nullptr;

  return false; // return true if if instance is found and removed & false if no instance is found
}

bool Library::remove_books(string title, string authors, string genre, string dop) { //same as above, but with provided attributes 
  Book *input_ptr = new Book(title, authors, genre, dop);

  for (int i = 0; i < book_list.size(); i++) { // check if the input book exists in the library
    if (*(input_ptr) == *(book_list[i])) {
      cout << "Removing " << title << "...\n" << endl;
      delete book_list[i];
      book_list.erase(book_list.begin() + i);
      is_borrowed.erase(is_borrowed.begin() + i);
      return true;
    }
  }
  // if input book is not found in the library, reject the removal
  cout << "Removal Rejected! " << title << " is not in the library!\n" << endl;
  delete input_ptr;
  input_ptr = nullptr;

  return false; // return true if if instance is found and removed & false if no instance is found
}

void Library::advanced_search(string title_input, string author_input, string genre_input) { //not defined inputs set to empty string
  bool is_found = false;

  cout << "Searching for " << title_input << "..." << endl;

  for (int i = 0; i < book_list.size(); ++i) {
    bool title_match = false, authors_match = false, genre_match = false; //bool variables for match of each attribute
    if (title_input != ""){
      title_match = book_list[i]->get_title().find(title_input) != string::npos;
    } 
    if (author_input != ""){
      authors_match = book_list[i]->get_authors().find(author_input) != string::npos;
    }
    if (genre_input != ""){
      genre_match = book_list[i]->get_genre().find(genre_input) != string::npos;
    }

   if (title_match && authors_match && genre_match){ //exact match
      cout << "Exact match found! Book details:\n";
      book_list[i]->print();
      is_found = true; 
    }
  else if (title_match || authors_match || genre_match) { // partial match
      cout << "Partial match found! Book details:\n";
      book_list[i]->print();
      is_found = true;
    }
  }

  if (!is_found) { //if no match was found
    cout << "There is no match for this book!\n";
  }
}

void Library::borrow_book(Student& user, string title, string genre){
  vector <string> user_valid_genres(user.get_genres());
  bool is_found = false;
  for (int i = 0; i < book_list.size(); i++) { // check if the input book exists in the library
    if (title == book_list[i] -> get_title() && is_borrowed[i] == false && user.get_borrowed_count() < user.get_borrow_limit() && 
       find(user_valid_genres.begin(), user_valid_genres.end(), genre) != user_valid_genres.end()) { //if all requirements are met
      is_found = true;
      cout << "Borrowing " << title << "...\n" << endl;
      is_borrowed[i] = true;
      user.borrow_incr(); 
    }
  }
  if (!is_found){ //if statements for different cases of why the borrowing is rejected
    if (find(user_valid_genres.begin(), user_valid_genres.end(), genre) == user_valid_genres.end()){
      cout << "This genre cannot be borrowed." << endl;
    }
    else if (user.get_borrowed_count() >= user.get_borrow_limit()){
      cout << "Borrow limit is reached! Cannot borrow book." << endl;
    }
    else{
      cout << "Borrowing failed! This book does not exist in the library or it is borrowed!" << endl;
    }
  }
}

void Library::borrow_book(Teacher& user, string title, string genre){ //same as above, but for teacher user
  vector <string> user_valid_genres(user.get_genres());
  bool is_found = false;

  for (int i = 0; i < book_list.size(); i++) { // check if the input book exists in the library
    if (title == book_list[i] -> get_title() && is_borrowed[i] == false && user.get_borrowed_count() < user.get_borrow_limit() && 
       find(user_valid_genres.begin(), user_valid_genres.end(), genre) != user_valid_genres.end()) {
      is_found = true;
      cout << "Borrowing " << title << "...\n" << endl;
      is_borrowed[i] = true;
      user.borrow_incr(); 
    }
  }
  if (!is_found){
    if (find(user_valid_genres.begin(), user_valid_genres.end(), genre) == user_valid_genres.end()){
      cout << "This genre cannot be borrowed." << endl;
    }
    else if (user.get_borrowed_count() >= user.get_borrow_limit()){
      cout << "Borrow limit is reached! Cannot borrow book." << endl;
    }
    else{
      cout << "Borrowing failed! This book does not exist in the library or it is borrowed!" << endl;
    }
  }
}

void Library::return_book(LibraryUser& user, string title){
  bool found_book = false;

  for(int i=0; i < book_list.size(); i++){
    if(title == book_list[i] -> get_title() && is_borrowed[i] == true){ //checks to see if titles match and if book is borrowed
      cout << user.get_name() << " is returning " << title << "..." << endl;
      is_borrowed[i] = false; //sets the borrowed status to false
      user.borrow_decr();
      found_book = true;
    }
  }
  if (!found_book){
    cout << "Cannot return book. " << title << " is either not in library or is not borrowed!" << endl;
  }
}

void Library::print() { // prints a list of books stored in library
  if (book_list.size() == 0) { //empty libraries
    cout << "This library is empty!" << endl;
  } 
  else {
    for (int i = 0; i < book_list.size(); i++) {
      cout << "Book " << i + 1 << ":" << endl;
      book_list[i]->print();
    }
  }
}

Book* Library::find_book_by_title(string title){ //method created to be used in update_book_details method for teacher users
  for (int i = 0; i < book_list.size(); i++){
    if (title == book_list[i] -> get_title()){
      return book_list[i]; //retursn a pointer to the matched book
    }
  }
  return nullptr;
}