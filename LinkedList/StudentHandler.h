#pragma once

#include "Student.h"

void printStudentInfo(Student_t student);
void printAllStudentsInfo();
Student_t* searchStudentById(int studentId);
Student_t* searchStudentByLastName(char* lastName);
void handler_addStudent(Student_t* student);