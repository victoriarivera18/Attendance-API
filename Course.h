// V. Rivera Casanova
// CSCE 121
// Yhang 512

#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include "Date.h"
#include "AttendanceRecord.h"

class Course {
  std::string id;
  std::string title;
  Date startTime;
  Date endTime;
  std::vector<AttendanceRecord> attendanceRecords;

public:
  Course(std::string id, std::string title, Date startTime, Date endTime):id(id), title(title), startTime(startTime), endTime(endTime){}
  std::string getID();
  std::string getTitle();
  Date getStartTime();
  Date getEndTime();
  void addAttendanceRecord(AttendanceRecord ar);
  void outputAttendance();
  void outputAttendance(std::string student_id);
};

#endif