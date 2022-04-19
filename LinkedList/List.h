#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef enum { OK, Empty, NOT_FOUND, FULL, FOUND }LinkedListReturnCode;

typedef struct LinkedList* LinkedList_t;
typedef struct Node* Node_t;

LinkedList_t create();
LinkedListReturnCode linked_list_destroy(LinkedList_t* self);
LinkedListReturnCode push(LinkedList_t self, void* item);
void* pull(LinkedList_t self);
LinkedListReturnCode linked_list_containsItem(LinkedList_t self, void* item);
LinkedListReturnCode removeItem(LinkedList_t self, void* item);
void* peekItemByIndex(LinkedList_t self, uint16_t index);

uint16_t linked_list_length(LinkedList_t self);

void linked_list_clear(LinkedList_t self);

LinkedListReturnCode printList(LinkedList_t self);