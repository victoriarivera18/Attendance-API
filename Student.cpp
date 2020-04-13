// V. Rivera Casanova
// CSCE 121
// Yhang 512

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Student.h"

using namespace std;

Student::Student(string student_id, string name)  // constructor
{ 
    id = student_id;
    this->name = name;  // using this instance
}


string Student::get_id()
{
    return this->id;
}


string Student::get_name()
{
    return this->name;
}


void Student::addCourse(string course_id)
{   
    bool there = false;
    for (unsigned int i = 0; i < course_ids.size(); i++) {
        if(course_ids.at(i) == course_id) {
            there = true;
            break;
        }
    }

    if(!there) {
        course_ids.push_back(course_id);  // assume this should add course id to vector
    }
}


void Student::listCourses()
{
    if (!course_ids.empty()) {
        cout << "Courses for " << this->get_id() << endl;
        for (unsigned int i = 0; i < course_ids.size(); i++) {  // prints vector values
            cout << course_ids.at(i) << endl;
        }
    }
}