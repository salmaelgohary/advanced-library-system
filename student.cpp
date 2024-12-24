#include <iostream>
using namespace std;

#include "libraryuser.hpp"
#include "student.hpp"

Student::Student() : LibraryUser(), graduated(false), borrow_limit(1) {} // set default values

Student::Student(string name, int user_id, int borrowed_count, bool graduated, int limit): LibraryUser(name, user_id, borrowed_count), graduated(graduated), borrow_limit(limit) {}

int Student::get_borrow_limit() { 
    return borrow_limit; 
}

vector <string> Student:: get_genres(){
    return valid_genres;
}

void Student::print() {
    cout << "This user is a Student: " << endl; //specifying what type of user this is
    LibraryUser::print_user(); //calling print method from LibraryUser to print inherited attributes
    cout << "User graduation status: ";
    if (graduated){ //turning the 0 or 1 value for graduated into yes or no
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }    
    
    cout << "User borrow limit: " << borrow_limit << endl;
    cout << "Valid genres for user: ";
    
    for(int i=0; i < valid_genres.size(); i++){ //print all the elements in the valid_genres vector
        cout << valid_genres[i] << ", ";
    }
    cout << endl;
}