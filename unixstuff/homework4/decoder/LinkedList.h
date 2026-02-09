#include <stdlib.h>  
#include <stdio.h>
#include <string.h>

/**
 * Actual nodes in our linked list
 */
typedef struct LinkedListNode
{
    char *value;

    struct LinkedListNode *next;

} LinkedListNode;

/**
 * A structure that represents our linked list
 */
typedef struct
{
    LinkedListNode *head;
    LinkedListNode *tail;

} LinkedList;