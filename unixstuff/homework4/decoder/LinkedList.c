#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include <stdio.h>


/**
 * Initialize a linked list to empty
 * @param list Pointer to the linked list struct
 */
void initialize_list(LinkedList *list)
{
    list->head = NULL;
    list->tail = NULL;
}

/**
 * Prepend a value onto the beginning of the list.
 * @param list Pointer to the linked list struct
 * @param value value to add to the list
 */
void prepend_list(LinkedList *list, const char *value)
{
    // Allocate a linked list node
    LinkedListNode *node = (LinkedListNode *)calloc(1, sizeof(LinkedListNode));
    node->next = list->head;
    
    // Copy the value into the list
    node->value = (char *)calloc(strlen(value) + 1, sizeof(char));
    strncpy(node->value, value, strlen(value));

    list->head = node;
}


/**
 * Free the memory allocated for our list
 * @param list Pointer to linked list object
 */
void free_list(LinkedList *list)
{
    LinkedListNode *node;

    for (node = list->head; node != NULL;  )
    {
        LinkedListNode *next = node->next;

        free(node->value);
        free(node);

        node = next;
    }

    list->head = NULL;
    list->tail = NULL;
}


void print_list(LinkedList *list)
{
    LinkedListNode *node;

    for (node = list->head; node != NULL; node = node->next)
    {
        printf("%s\n", node->value);
    }
}


void shift(char * value, const char *key, int row) {
    int length = strlen(value);
    char temp [length + 1];
    int shiftAmount = row % length;

    strncpy(temp, value + shiftAmount, length - shiftAmount);
    strncpy(temp + (length - shiftAmount), value, shiftAmount);
    
    temp[length] = '\0';
    
    strncpy(value, temp, length);
    return;
}

void decode(LinkedList *list, const char * key, int row)
{
    LinkedListNode *node;

    for (node = list->head; node != NULL; node = node->next)
    {
        int length = strlen(node->value); 

        for (int i = 0; i < length; i++) {
            if ((node->value[i] + key[i]) % 2 == 1) {
                node->value[i] = '1';
            } else {
                node->value[i] = '0'; 
            }
        }
        shift(node->value, key, row - 1);
        row--;
    }
}

void convert(LinkedList *list) {
    LinkedListNode *node;

    for (node = list->head; node != NULL; node = node->next)
    {
        for (int i = 0; i < strlen(node->value); i++) {
            if (node->value[i] == '1') {
                node->value[i] = 'X';
            } else {
                node->value[i] = ' '; 
            }
        }
    }
}
