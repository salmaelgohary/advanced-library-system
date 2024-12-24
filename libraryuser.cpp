#include <iostream>
#include <string>
using namespace std;
#include "libraryuser.hpp"

LibraryUser::LibraryUser() : name("Unknown"), user_id(00000000), borrowed_count(0) {} //setting default values

LibraryUser::LibraryUser(string name, int user_id, int borrowed_count) : name(name), user_id(user_id), borrowed_count(borrowed_count) {}

string LibraryUser::get_name() {
     return name; 
}

int LibraryUser::get_user_id() {
     return user_id; 
}

int LibraryUser::get_borrowed_count() {
     return borrowed_count; 
}

void LibraryUser::borrow_incr() { //increments borrowed count of user
    ++borrowed_count; 
}

void LibraryUser::borrow_decr() { //decrements borrowed count of user
    --borrowed_count; 
}

void LibraryUser::print_user() { //prints out all the attributes
  cout << "User's information: " << endl;
  cout << "User name: " << name << endl;
  cout << "User ID: " << user_id << endl;
  cout << "User borrowed count: " << borrowed_count << endl;
}
