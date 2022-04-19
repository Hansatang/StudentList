#include "Student.h"
#include <stdlib.h>
#include <string.h>

typedef struct Student {
	char firstName[20];
	char lastName[20];
	int studentId;
	char nationality[20];
} Student;

char* student_getName(Student_t self)
{
	return self->firstName;
}

Student_t student_create(char* firstName, char* lastName, int studentId, char* nationality) {
	Student_t _student = malloc(sizeof(Student));
	if (NULL == _student) {
		return NULL;
	}
	strncpy(_student->firstName, firstName, sizeof(_student->firstName) - 1);
	strncpy(_student->lastName, lastName, sizeof(_student->lastName) - 1);
	_student->studentId = studentId;
	strncpy(_student->nationality, nationality, sizeof(_student->nationality) - 1);
	return _student;
};
void printInfo(Student_t self) {
	printf("FirstName : %s, LastName : %s, StudentId : %i, Nationality : %s\n", student_getName(self), (char*)self->lastName, self->studentId, self->nationality);
};

