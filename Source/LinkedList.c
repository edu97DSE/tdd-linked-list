/*!
 * @file
 * @brief Implementation of singly-linked list.
 */

#include "stdio.h"
#include "stdlib.h"
#include "LinkedList.h"

void LinkedList_Init(LinkedList_t *instance)
{
    instance->head = NULL;
}

uint16_t LinkedList_Count(LinkedList_t *instance)
{
    LinkedListNode_t *node = instance->head;
    uint16_t length = 0;

    while (node != NULL)
    {
        node = node->next;
        length++;
    }
    return length;
}

void LinkedList_PushFront(LinkedList_t *instance, LinkedListNode_t *node)
{
    node->next = instance->head;
    instance->head = node;
}

void LinkedList_PushBack(LinkedList_t *instance, LinkedListNode_t *node)
{
    LinkedListNode_t *address = instance->head;
    if (instance->head == NULL)
    {
        node->next = instance->head;
        instance->head = node;
    }
    else
    {
        node->next = NULL;
        while (address->next != NULL)
        {
            address = address->next;
        }
        address->next = node;
    }
}

LinkedListNode_t *LinkedList_PopBackRemoves(LinkedList_t *instance)
{
    LinkedListNode_t *node = instance->head;
    LinkedListNode_t *lastElement;
    while(node->next->next != NULL)
    {
        node = node->next;
    }
    lastElement = node->next;
    node->next = NULL;
    return lastElement;
}

LinkedListNode_t *LinkedList_PopFrontRemoves(LinkedList_t *instance)
{
    LinkedListNode_t *firstElement = instance->head;
    instance->head = NULL;
    instance->head = firstElement->next;
    return firstElement;
}

void LinkedList_RemoveNodeIfIsInList(LinkedList_t *instance, LinkedListNode_t *nodeToDelete)
{
    LinkedListNode_t *listElement = instance->head;

    if(instance->head == nodeToDelete)
    {
        instance->head = NULL;
        instance->head = listElement->next;
    }
    else
    {
       while(listElement->next != nodeToDelete && listElement->next != NULL)
       {
         listElement = listElement->next;
       } 
       if(listElement->next != NULL)
       {
           listElement->next = listElement->next->next;
       }
    }  
}
