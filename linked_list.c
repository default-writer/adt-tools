/** @file linked_list.c */

#include "linked_list.h"


/********************************************//**
 * @brief Checks if the list is empty. The macro will
 * return true if there are no nodes in the list or the
 * list has not yet been initiated.
 *
 * @param x
 * @return #define
 *
 ***********************************************/
#define ADT_IS_EMPTY(x) (x == NULL);

/********************************************//**
 * @brief Creates a new instance of the ADT_List object
 * & return the the list head.
 * @param data void* generic data type
 * @return ADT_List*
 *
 ***********************************************/
ADT_List *ADT_list_new(void *data)
{
    ADT_List *l = malloc(sizeof(ADT_List));
    l->data = data;
    l->next = NULL;
    return l;
}

/********************************************//**
 * @brief Inserts an ADT_List at the tail position of
 * the list. The list will remain in the head position
 * after this routine has been run.
 *
 * @param list the head of the list
 * @param data a pointer to pre allocated memory holding
 * the void *data ref.
 * @return
 *
 ***********************************************/
int ADT_list_insert(ADT_List *const list, void *data)
{
    ADT_List *tempList = list;
    while(tempList->next != NULL)
    {
        tempList = tempList->next;
    }
    tempList->next = malloc(sizeof(ADT_List));
    if (tempList->next == NULL)
    {
         printf("Error: unable to allocate memory");
         return ADT_ALLOC_ERROR;
    }
    tempList->next->data = data;
    tempList->next->next = NULL;
    return ADT_NO_ERROR;
}

/********************************************//**
 * @brief Delete a single ADT_List node from the list.
 * The list lookup requires a valid void *data reference.
 * This function also cleans up the memory the void *data
 * points to. If there is an error allocating memory then
 * this function will return a the value of ADT_ALLOC_ERROR.
 * @param list ADT_List*
 * @param data void* There must be a valid data reference
 * @return void*
 *
 ***********************************************/
void *ADT_list_delete(ADT_List *list, void *data)
{
    ADT_List *tempPtr = list;
    ADT_List *prevPtr;
    // check if the current head of the list contains the same ref to data
    // & compare the address from void *data
    if (list->data == data)
    {
        tempPtr = list; // temporarily store node being deleted
        list = list->next;
        free(tempPtr->data);
        free(tempPtr);
    }
    else
    {
      while(tempPtr->data != data)
      {
          prevPtr = tempPtr;
          tempPtr = list->next;
      }
      prevPtr->next = tempPtr->next;
      free(tempPtr->data);
      free(tempPtr);
    }
    return data;
}



//
//void insertAtEnd(ADT_List *head, char value)
//{
//    ADT_List current = *head;
//
//    if (current == NULL)
//    {
//        // there are no nodes so add the first
//        current = malloc(sizeof(node_t));
//        current->data = value;
//        current->next = NULL;
//        *head = current;
//    }
//    else
//    {
//        while(current->next != NULL)
//        {
//            // set current to the last node
//            current = current->next;
//        }
//        current->next = malloc(sizeof(node_t));
//        current->next->data = value;
//        current->next->next = NULL;
//    }
//}
//
//
//
//void insert(ADT_List *head, char value)
//{
//    ADT_List newPtr;
//    ADT_List previousPtr;
//    ADT_List currentPtr;
//
//    newPtr = malloc(sizeof(node_t));
//
//    // check if space is available
//    if (newPtr != NULL)
//    {
//        newPtr->data = value;
//        newPtr->next = NULL;
//
//        previousPtr = NULL;
//        currentPtr = *head;
//
//        while(currentPtr->next != NULL && value > currentPtr->data)
//        {
//            previousPtr = currentPtr;
//            currentPtr = currentPtr->next;
//        } /* end while */
//        if (previousPtr == NULL)
//        {
//            // no nodes so create first node at beginning of list
//            *head = newPtr;
//        }
//        else
//        {
//            // insert a new node between the previous and current nodes
//            previousPtr->next = newPtr;
//            newPtr->next = currentPtr;
//        }
//    }
//    else
//    {
//        printf("Error %c not inserted. No memory available.\n", value);
//    }
//    // TODO return int error
//}
//
//
//
//char delete(ADT_List *head, char value)
//{
//    ADT_List previousPtr;
//    ADT_List currentPtr;
//    ADT_List tempPtr;
//
//    if (value == (*head)->data)
//    {
//        tempPtr = *head; // store node being deleted
//        *head = (*head)->next;
//        free(tempPtr);
//    }
//    else
//    {
//        previousPtr = *head;
//        currentPtr = (*head)->next;
//
//        while(currentPtr != NULL && currentPtr->data != value)
//        {
//            previousPtr = currentPtr;
//            currentPtr = currentPtr->next;
//        }
//        if (currentPtr != NULL)
//        {
//            tempPtr = currentPtr;
//            previousPtr->next = currentPtr->next;
//            free(tempPtr);
//            return value;
//        }
//    }
//    return '\0';
//}
//
//
//void deleteAtPosition(ADT_List *head, int pos)
//{
//    int length = 0;
//    ADT_List currentPtr;
//    ADT_List previousPtr;
//    currentPtr = *head;
//    if (*head == NULL)
//    {
//        printf("Error: Nothing to delete\n");
//        return '\0';
//    }
//    if (pos == 1)
//    {
//        *head = currentPtr->next;
//    }
//    else
//    {
//        while(currentPtr != NULL)
//        {
//            currentPtr = currentPtr->next;
//            length++;
//        }
//        if (pos > 0 && pos <= length)
//        {
//            for(int i = 1; i < pos; i++)
//            {
//                previousPtr = currentPtr;
//                currentPtr = currentPtr->next;
//            }
//            previousPtr->next = currentPtr->next;
//        }
//        else
//        {
//            printf("Error: out of range\n");
//            return '\0';
//        }
//
//    }
//    free(currentPtr);
//}
//
//
//void printList(ADT_List currentPtr)
//{
//    if (currentPtr == NULL)
//    {
//        printf("List is empty\n\n");
//    }
//    else
//    {
//        printf("The list is:\n");
//        while(currentPtr != NULL)
//        {
//            currentPtr = currentPtr->next;
//        }
//        printf("NULL\n\n");
//    }
//}
//
//

//
//
