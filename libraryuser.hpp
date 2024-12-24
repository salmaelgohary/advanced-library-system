#ifndef LIBRARYUSER_HPP

#define LIBRARYUSER_HPP

#include <string>
#include <iostream>
using namespace std;

class LibraryUser{
    string name;
    int user_id, borrowed_count;

    public:
    LibraryUser();
    LibraryUser(string name, int user_id, int borrowed_count);

    string get_name();
    //PURPOSE: access name of the user 
    //INPUT: None
    //OUTPUT: name of user

    int get_user_id();
    //PURPOSE: access user ID 
    //INPUT: None
    //OUTPUT: ID of the user

    int get_borrowed_count();
    //PURPOSE: access the number of books borrowed by user 
    //INPUT: None
    //OUTPUT: borrowed count of user

    void borrow_incr();
    //PURPOSE: increment borrowed count of user by 1
    //INPUT: None
    //OUTPUT: none

    void borrow_decr();
    //PURPOSE: decrement borrowed count of user by 1 
    //INPUT: None
    //OUTPUT: none

    void print_user();
    //PURPOSE: print user details (name, ID, borrowed count)
    //INPUT: None
    //OUTPUT: none
};

#endif