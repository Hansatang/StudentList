#pragma once

#include "Student.h"
#include "List.h"

LinkedListReturnCode addStudent(Student_t student);
LinkedListReturnCode getStudent(Student_t student);
LinkedListReturnCode removeStudent(Student_t student);
int noOfStudents();