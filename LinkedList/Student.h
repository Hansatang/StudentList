#pragma once

typedef struct Student* Student_t;

Student_t student_create(char* firstName, char* lastName, char* studentId, char* nationality);
void printInfo(Student_t self);