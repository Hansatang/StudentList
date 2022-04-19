#include "StudentHandler.h"

void printStudentInfo(Student_t student) {
	printInfo(student);
};
void printAllStudentsInfo();
Student_t* searchStudentById(int studentId);
Student_t* searchStudentByLastName(char* lastName);
void handler_addStudent(Student_t* student) {
	addStudent(student);
};