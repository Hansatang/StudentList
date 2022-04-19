#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


typedef struct Node {
	void* item;
	Node_t* next;
} Node;

typedef struct LinkedList {
	Node_t* root;
} LinkedList;

LinkedList_t create() {
	LinkedList_t _newList = malloc(sizeof(LinkedList));
	if (NULL == _newList) {
		return NULL;
	}
	//yay
	_newList->root = NULL;
	return _newList;
};

LinkedListReturnCode push(LinkedList_t self, void* item) {
	return inside_push(&self->root, item);
};

LinkedListReturnCode inside_push(Node_t** _checkedNode, void* item) {
	struct Node* _newNode = malloc(sizeof(struct Node));
	_newNode->item = item;
	_newNode->next = NULL;

	if (*_checkedNode == NULL)
	{
		*_checkedNode = _newNode;
		printf("Insert\n");
		if (*_checkedNode == NULL)
		{
			printf("Second\n");
		}
		return OK;
	}
	else
	{
		struct Node* current = *_checkedNode;
		while (1) { // Change 2
			printf("Zoink : %s\n", (char*)current->item);
			printf("Mono : %s\n", (char*)item);
			if (current->next != NULL)
			{
				current = current->next;
			}
			else if (current->next == NULL)
			{
				printf("Monolit : %s\n", (char*)item);
				current->next = _newNode;
				printf("added later\n");
				return OK;
				// Change 3
			}

		};
	}


}

LinkedListReturnCode linked_list_destroy(LinkedList_t* self) {

	free(*self);
	*self = NULL;
	return 0;
};

uint16_t linked_list_length(LinkedList_t self) {
	uint16_t i = 0;
	Node_t _checkedNode;
	for (_checkedNode = self->root; _checkedNode != NULL; _checkedNode = _checkedNode->next) {
		i++;
	}
	return i;
};

LinkedListReturnCode linked_list_containsItem(LinkedList_t self, void* item) {
	if (self == NULL)
	{
		printf("Self is null\n");
		return 1;
	}
	Node_t _checkedNode = self->root;
	while (1)
	{
		if (_checkedNode == NULL)
		{
			printf("checked is null\n");
			return 2;
		}
		else {

			printf("Peek1 : %s\n", (char*)_checkedNode->item);
			printf("Peek2 : %s\n", (char**)item);
			if (*(char*)_checkedNode->item == *(char*)item)
			{
				printf("checked matches fooo\n");
				return 4;
			}
			else if (_checkedNode->item != item)
			{
				printf("Peek : %s\n", _checkedNode->item);
				printf("recursion\n");
				_checkedNode = _checkedNode->next;

			}
		}
	}
};

LinkedListReturnCode removeItem(LinkedList_t self, void* item) {
	struct Node* _checkedNode = self->root;
	struct Node* _checkedNode2 = _checkedNode->next;

	if (*(char*)_checkedNode->item == *(char*)item) {
		if (_checkedNode2 == NULL)
		{
			_checkedNode = NULL;
		}
		else
		{
			_checkedNode->item = _checkedNode2->item;
			_checkedNode->next = _checkedNode2->next;
		}
		return OK;
	}

	else {
		while (1)
		{
			struct Node* _checkedNode3 = _checkedNode2->next;
			if ((char*)_checkedNode2->item == (char*)item) {
				printf("Found\n");
				if (_checkedNode2->next == NULL)
				{
					_checkedNode->next = NULL;
				}
				else {

					_checkedNode->next = _checkedNode3;
				}
				return OK;
			}
			else if (_checkedNode2->next == NULL)
			{
				return 2;
			}
			else
			{
				_checkedNode = _checkedNode2;
				_checkedNode2 = _checkedNode3;
				_checkedNode3 = _checkedNode2->next;

			}
		}


	}

};
void* peekItemByIndex(LinkedList_t self, uint16_t index) {
	int i = 0;
	Node_t _checkedNode = self->root;
	while (i != index) {
		_checkedNode = _checkedNode->next;
		i++;
	}
	return _checkedNode->item;
};



void linked_list_clear(LinkedList_t self) {
	self->root = NULL;
};


LinkedListReturnCode printList(LinkedList_t self) {
	if (self == NULL)
	{
		printf("Self is null\n");
		return 1;
	}
	Node_t _checkedNode = self->root;
	while (1)
	{
		if (_checkedNode == NULL)
		{
			printf("checked is null\n");
			return 1;
		}
		else {
			if (_checkedNode->item != NULL)
			{

				printf("Item : %s\n", (char*)_checkedNode->item);
			}

			if (_checkedNode->next == NULL)
			{
				return 1;
			}
			else if (_checkedNode->next != NULL)
			{
				_checkedNode = _checkedNode->next;
			}

		}
	}
};

void* pull(LinkedList_t self) {
	Node_t _checkedNode = self->root;
	while (1)
	{

		if (_checkedNode->next != NULL) {
			_checkedNode = _checkedNode->next;
		}
		else
		{
			return _checkedNode->item;
		}
	};
}