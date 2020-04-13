// V. Rivera Casanova
// CSCE 121
// Yhang 512


#ifndef ATTENDANCERECORD_H
#define ATTENDANCERECORD_H

#include <string>
#include "Date.h"

class AttendanceRecord {
  std::string course_id;
  std::string student_id;
  Date time;

public:
  AttendanceRecord(std::string course_id, std::string student_id, Date time): course_id(course_id), student_id(student_id), time(time) {}
  std::string getCourseID();
  std::string getStudentID();
  Date getDate();
};

#endif