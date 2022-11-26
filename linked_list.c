/** @file linked_list.c */

#include "linked_list.h"


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

