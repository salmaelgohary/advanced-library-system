#ifndef STUDENT_HPP

#define STUDENT_HPP

#include <string>
#include <vector>
#include <iostream>
#include "libraryuser.hpp"

using namespace std;

class Student : public LibraryUser{ //students can borrow fewer books than teachers
    bool graduated;
    int borrow_limit;
    vector <string> valid_genres = {"Fantasy", "Romance", "Sci-fi"};

    public:
    Student(); //default constructor
    Student(string name, int user_id, int borrowed_count, bool graduated, int limit); //parametrized constructor

    int get_borrow_limit();
    //PURPOSE: Get access to the borrow limit 
    //INPUT: None
    //OUTPUT: The borrow limit number of the student
    
    vector <string> get_genres();
    //PURPOSE: Get access to the valid genres for a student 
    //INPUT: None
    //OUTPUT: The valid genres for a student 

    void print();
    //PURPOSE: print out all the details about a student user
    //INPUT: None
    //OUTPUT: None
};

#endif