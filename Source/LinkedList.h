/*!
 * @file
 * @brief Singly-linked list data structure.
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedListNode_t
{
   struct LinkedListNode_t *next;
} LinkedListNode_t;

typedef struct
{
   LinkedListNode_t *head;
} LinkedList_t;

void LinkedList_Init(LinkedList_t *instance);
uint16_t LinkedList_Count(LinkedList_t *instance);
void LinkedList_PushFront(LinkedList_t *instance, LinkedListNode_t *node);
void LinkedList_PushBack(LinkedList_t *instance, LinkedListNode_t *node);
LinkedListNode_t *LinkedList_PopBackRemoves(LinkedList_t *instance);
LinkedListNode_t *LinkedList_PopFrontRemoves(LinkedList_t *instance);
void LinkedList_RemoveNodeFromTheList(LinkedList_t *instance, LinkedListNode_t *nodeToDelete);

// TODO
// Count -- Get the number of elements in the list
// PushFront -- Add element to the head (front) of the list
// PushBack -- Add element to the tail (back) of the list
// PopFront -- Remove and return the element at the head (front) of the list
// PopBack -- Remove and return the element at the tail (back) of the list
// Remove -- Remove a specific element from the list given its pointer
// At -- Returns the element at a specified index

#endif
