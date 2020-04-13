// V. Rivera Casanova
// CSCE 121
// Yhang 512


#include <iostream>
#include <fstream>
#include <string>
#include "Course.h"
#include "Date.h"
#include "AttendanceRecord.h"

using namespace std;


string Course::getID()
{
    return this->id;
}                 


string Course::getTitle()
{
    return this->title;
}


Date Course::getStartTime()
{
    return this->startTime;
}


Date Course::getEndTime()
{
    return this->endTime;
}


void Course::addAttendanceRecord(AttendanceRecord ar)
{
    bool added = false;
    Date current = ar.getDate();
    if (current.operator>=(startTime) && current.operator<=(endTime)) {
        attendanceRecords.push_back(ar);
        added = true;
    }

    if (!added) {
        cout << "did not save this record." << endl;
    }
}


void Course::outputAttendance()
{
    if (!attendanceRecords.empty()) {
        for (unsigned int i = 0; i < attendanceRecords.size(); i++) {
            cout << ((attendanceRecords.at(i)).getDate()).getDateTime() << "," << attendanceRecords.at(i).getCourseID() << "," <<(attendanceRecords.at(i)).getStudentID() << endl;
        }
    } else {
        cout << "No Records" << endl;
    }
}


void Course::outputAttendance(string student_id)
{   
    int count = 0;
    if (!attendanceRecords.empty()) {
        for (unsigned int i = 0; i < attendanceRecords.size(); i++) {
            if ((attendanceRecords.at(i)).getStudentID() == student_id) {
                cout << ((attendanceRecords.at(i)).getDate()).getDateTime() << "," << attendanceRecords.at(i).getCourseID() << "," << student_id << endl;
                count ++;
            }
        }
    }

    if (count == 0) {
         cout << "No Records" << endl;
    }
}
