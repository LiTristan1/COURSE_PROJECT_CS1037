#include <stdio.h>
#include <stdlib.h>
#ifndef HUFFMANLINKED_H
#define HUFFMANLINKED_H

// linked list to first get list of characters and their frequencies
typedef struct lnode
{
    char character;
    int instances;
    struct lnode *next;
    struct lnode *previous;
} LinkedNode;

// Define queue type linkedlist
typedef struct
{
    LinkedNode *front;
    LinkedNode *rear;
    int count;
} LList;

// Define boolean in C
enum BOOLEAN
{
    FALSE,
    TRUE
};
// Determines if the character has already appeared or not
int hasInstance(LList *list, char c);
// Insert new node into linked list
void insertLinkedNode(LList *list, char c);
void deleteLinkedNode(LList *list, int index);
// Increment the node with char c instances by 1
void updateList(LList *list, char c);
// Sort Linked List by frequencies
void sortLinkedList(LList *list);
// Prints each character and corresponding frequencies in the linked list
void printInfo(LList *list);
// function to read file and return array with frequencies of each character
LList *readFile(FILE *file, char *path, LList *list);
// Finds if character has already been counted

#endif
