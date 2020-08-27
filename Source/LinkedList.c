/*!
 * @file
 * @brief Implementation of singly-linked list.
 */

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "LinkedList.h"
#include "uassert.h"

void LinkedList_Init(LinkedList_t *instance)
{
    instance->head = NULL;
}

uint16_t LinkedList_Count(LinkedList_t *instance)
{
    LinkedListNode_t *node = instance->head;
    uint16_t listLength = 0;

    while (node != NULL)
    {
        node = node->next;
        listLength++;
    }
    return listLength;
}

static bool LinkedList_VerifyIfNodeIsInList(LinkedList_t *instance, LinkedListNode_t *nodeToFind)
{
    LinkedListNode_t *listElement = instance->head;
    bool flagNodeAlreadyExist = false;

    if(instance->head == nodeToFind->next)
    {
        flagNodeAlreadyExist = true;
    }
    while(listElement->next != nodeToFind->next && listElement->next != NULL)
    {
        listElement = listElement->next;
    } 
    if(listElement->next == nodeToFind->next)
    {
        flagNodeAlreadyExist = true;
    }
    return flagNodeAlreadyExist;
}

void LinkedList_PushFront(LinkedList_t *instance, LinkedListNode_t *nodeToAdd)
{
    if(!LinkedList_VerifyIfNodeIsInList(&instance, &nodeToAdd))
    {
        nodeToAdd->next = instance->head;
        instance->head = nodeToAdd;
    }
    else
    {
        uassert(false);
    } 
}

void LinkedList_PushBack(LinkedList_t *instance, LinkedListNode_t *nodeToAdd)
{
    LinkedListNode_t *listElement = instance->head;
    
    if(!LinkedList_VerifyIfNodeIsInList(&instance, &nodeToAdd))
    {
        if(instance->head == NULL)
        {
            nodeToAdd->next = instance->head;
            instance->head = nodeToAdd;
        }
        else
        {
            nodeToAdd->next = NULL;
            while(listElement->next != NULL)
            {
                listElement = listElement->next;
            }
            listElement->next = nodeToAdd;
        }
    }
    else
    {
        uassert(false);
    }
}

LinkedListNode_t *LinkedList_PopBackRemoves(LinkedList_t *instance)
{
    LinkedListNode_t *nodeToRemove = instance->head;
    LinkedListNode_t *lastElement;
    while(nodeToRemove->next->next != NULL)
    {
        nodeToRemove = nodeToRemove->next;
    }
    lastElement = nodeToRemove->next;
    nodeToRemove->next = NULL;
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

LinkedListNode_t *LinkedList_GetTheNodeAtAnIndex(LinkedList_t * instance, uint16_t index)
{
   LinkedListNode_t *node = instance->head;
   for(int i = 0; i < index; i++)
   {
       node = node->next;
   }
   return node; 
}
