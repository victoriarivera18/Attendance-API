// V. Rivera Casanova
// CSCE 121
// Yhang 512

#include <iostream> 
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "School.h"
#include "AttendanceRecord.h"

using namespace std;

void School::addCourses(string filename)
{
  ifstream ifs(filename);
  if (!ifs.is_open()) {  // when file cannot open
    cout << "Unable to open file: " << filename << endl;
    return;
  }

  int startHour;
  int startMin;
  int endHour;
  int endMin;
  string line;
  string temp;
  string temp2;
  while (!ifs.eof()) {
    bool isIn = false;
   
    getline(ifs, line);
    istringstream ss(line);
    string id;  // gets id
    getline(ss, id, ',');

    // use sstream to convert string into int value for Date Object
    string startT;  // gets start hour ends at :
    getline(ss, startT, ',');

    string endT;  // gets start min
    getline(ss, endT, ',');

    string title; 
    getline(ss, title);


    if (!ss.fail()) {  // if all is well
      // need to create 2 Date objects
      for (unsigned int j = 0; j < courses.size(); j++) {  // checking to see if course already in list
        if (title == (courses.at(j)).getTitle()) {
          isIn = true;
        }
      }

      if (!isIn) {  // if not duplicate course
        temp = startT.substr(startT.find(':') + 1);
        startHour = stoi(startT);
        startMin = stoi(temp);
        temp2 = endT.substr(endT.find(':') + 1);
        endHour = stoi(endT);
        endMin = stoi(temp2);

        Date start(startHour, startMin);
        Date end(endHour, endMin);
        courses.push_back(Course(id, title, start, end));
      }
    }
  }
}


void School::addStudents(string filename) 
{
 ifstream ifs(filename);
  if (!ifs.is_open()) {
    cout << "Unable to open file: " << filename << endl;
    return;
  }
  while (!ifs.eof()) {
    string line;
    getline(ifs, line);
    istringstream ss(line);
    string uin;
    getline(ss, uin, ',');
    string name;
    getline(ss, name);
    if (!ss.fail()) {
      students.push_back(Student(uin, name));
    }
  }
}


void School::listStudents()
{
  if (!students.empty()) {  // is  vector is not empty
    for (unsigned int i = 0; i < students.size(); i++) {  // prints vector values of students
      cout << (students.at(i)).get_id() << "," << (students.at(i)).get_name() << endl;
    }
  } else {
      cout << "No Students" << endl;
    }
}


void School::listCourses() 
{
  if (!courses.empty()) {  // is  vector is not empty
    for (unsigned int i = 0; i < courses.size(); i++) {  // prints vector values of students
      cout << (courses.at(i)).getID() << "," << (courses.at(i)).getStartTime().getTime(false) << "," << (courses.at(i)).getEndTime().getTime(false) << "," << (courses.at(i)).getTitle() << endl;
    }
  } else {
      cout << "No Courses" << endl;
    }
}


void School::addAttendanceData(string filename)
{
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;
  string date;
  string c_id;
  string uin;
  string temp;
  string temp2;

  ifstream ifs(filename);
  if (!ifs.is_open()) {  // when file cannot open
    cout << "Unable to open file: " << filename << endl;
    return;
  }

  while (!ifs.eof()) {
    string line;
    getline(ifs, line);
    istringstream ss(line);

    getline(ss, date, ',');

    getline(ss, c_id, ',');

    getline(ss, uin);

    if (!ss.fail()) {
        year = stoi(date.substr(0, date.find('-')));
        temp = date.substr(date.find('-') + 1);
        month = stoi(temp.substr(0, temp.find('-')));
        temp2 = temp.substr(temp.find('-') + 1);
        day = stoi(temp2.substr(0, temp2.find(' ')));
        temp = temp2.substr(temp2.find(' ') + 1);
        hour = stoi(temp.substr(0, temp.find(':')));
        temp2 = temp.substr(temp.find(':') + 1);
        minute = stoi(temp2.substr(0, temp2.find(':')));
        temp = temp2.substr(temp2.find(':') + 1);
        second = stoi(temp);

      Date att(year, month, day, hour, minute, second);
      AttendanceRecord curr(c_id, uin, att);  // new record

      for (unsigned int k = 0; k < courses.size(); k++) {
        if ((courses.at(k)).getID() == c_id) {  // if the course matches info for current record add to attendance record
          (courses.at(k)).addAttendanceRecord(curr);
        }
      }
    }
  }
  
}


void School::outputCourseAttendance(string course_id)
{
  int spot;
  bool found = false;
  for (unsigned int k = 0; k < courses.size(); k++) {
      if ((courses.at(k)).getID() == course_id) {
        spot = k;
        found = true;
        break;
      }
  }
  if (found) {
    (courses.at(spot)).outputAttendance();
  }
}


void School::outputStudentAttendance(string student_id, string course_id)
{
  int spot;
  bool found = false;
  for (unsigned int k = 0; k < courses.size(); k++) {
    if ((courses.at(k)).getID() == course_id) {
      spot = k;
      found = true;
      break;
    }
  }
  if (found) {
    (courses.at(spot)).outputAttendance(student_id);
  }
}