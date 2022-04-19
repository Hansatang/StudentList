#include "StudentList.h"

LinkedList_t list;

LinkedListReturnCode addStudent(Student_t student) {
	if (list == NULL)
	{
		list = create();
	}
	return push(list, student);
}
;
LinkedListReturnCode getStudent(Student_t student);
LinkedListReturnCode removeStudent(Student_t student);
int noOfStudents() {

	return linked_list_length(list);
};