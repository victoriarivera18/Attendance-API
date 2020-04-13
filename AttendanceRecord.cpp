// V. Rivera Casanova
// CSCE 121
// Yhang 512

#include <string>
#include "AttendanceRecord.h"
#include "Date.h"

using namespace std;

string AttendanceRecord::getCourseID()
{
    return this->course_id;
}


string AttendanceRecord::getStudentID()
{
    return this->student_id;
}


Date AttendanceRecord::getDate()
{
    return this->time;
}