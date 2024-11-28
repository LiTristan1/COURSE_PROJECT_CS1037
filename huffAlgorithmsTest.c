#include <stdio.h>
#include "HuffmanLinked.h"

int main()
{
    FILE *file;
    char *path = "./Testing_files/short.txt";
    LList *list = (LList *)malloc(sizeof(LList));
    list->front = NULL;
    list->rear = NULL;
    list->count = 0;
    readFile(file, path, list);
    printf("Sorting list: \n");
    sortLinkedList(list);
    printInfo(list);
    // Testing insertion sort
    /*
    sortLinkedList(list,arr);
    printf("After sorting\n");
    for(int i = 0; i < 10; i++){
        printf("%d\n",*(arr + i));
    }
    */
}