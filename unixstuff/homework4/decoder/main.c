#include <stdio.h>
#include <string.h>
#include "LinkedList.h"

void initialize_list(LinkedList *list);
void append_list(LinkedList *list, const char *value);
void prepend_list(LinkedList *list, const char *value);
void free_list(LinkedList *list);
void print_list(LinkedList *list);
void decode(LinkedList *list, const char *key, int count);
void convert(LinkedList *list);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: decoder file\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("Unable to open input file\n");
        return 1;
    }
    
    char buffer[1024];

    fgets(buffer, sizeof(buffer), fp);
    char *token = strtok(buffer, " ,.-\n");
    char key[1024];
    strcpy(key, token);
    
    LinkedList list;
    initialize_list(&list);

    int count = 0;
    while(fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        char *token = strtok(buffer, " ,.-\n");
        prepend_list(&list, token);
        count++;
    }
    
    decode(&list, key, count);
    convert(&list);
    print_list(&list);

    free_list(&list);

    fclose(fp);
}