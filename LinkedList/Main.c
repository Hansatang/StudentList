#include "List.h"
#include "Student.h"
#include "StudentList.h"
#include "StudentHandler.h"


static void _printStatus(LinkedListReturnCode status)
{
	if (status == 0)
	{
		printf("Ok\n");
	}
	else if (status == 1) {
		printf("EMPTY\n");
	}
	else if (status == 2) {
		printf("NOT_FOUND\n");
	}
	else if (status == 3) {
		printf("FULL\n");
	}
	else if (status == 4) {
		printf("FOUND\n");
	}
	else
	{
		printf("Yoink\n");
	}
}

int main(void) {
	Student_t student = student_create("Johnando", "Jacskon", 1, "USA");
	Student_t student2 = student_create("Maciej", "Kowalski", 2, "POLAND");
	printInfo(student);
	printStudentInfo(student);
	handler_addStudent(student);
	handler_addStudent(student2);
	/*addStudent(student);
	addStudent(student2);*/
	printf("Lenght of Student list : %i\n", noOfStudents());
	LinkedList_t testList = create();
	push(testList, "test");
	push(testList, "string");
	push(testList, "rang");
	printf("Lenght : %i\n", linked_list_length(testList));
	printList(testList);
	_printStatus(linked_list_containsItem(testList, "string"));
	_printStatus(removeItem(testList, "string"));
	_printStatus(linked_list_containsItem(testList, "string"));
	printList(testList);

	//	_printStatus(linked_list_containsItem(myList, "strin"));
		/*_printStatus(linked_list_containsItem(myList, "strang"));
		push(myList, "strang");
		_printStatus(linked_list_containsItem(myList, "strin"));
		_printStatus(linked_list_containsItem(myList, "strang"));
		printf("End\n");
		printf("Lenght : %i\n", linked_list_length(myList));
		printf("Peek : %s\n", peekItemByIndex(myList,1));
		_printStatus(linked_list_containsItem(myList, "strin"));
		_printStatus(linked_list_containsItem(myList, "strin"));
		_printStatus(linked_list_containsItem(myList, "strang"));
		printf("Lenght : %i\n", linked_list_length(myList));
		printf("Pull : %s\n", pull(myList));
		_printStatus(removeItem(myList, "strin"));
		printf("Lenght : %i\n", linked_list_length(myList));
		_printStatus(linked_list_containsItem(myList, "strin"));
		printf("Pull : %s\n", pull(myList));
		linked_list_clear(myList);
		_printStatus(linked_list_containsItem(myList, "strang"));
		_printStatus(linked_list_containsItem(myList, "string"));*/

}