#include "HuffmanLinked.h"

int hasInstance(LList *list, char c)
{

    LinkedNode *iterate = list->front;
    if (iterate == NULL)
    {
        return 0;
    }
    while (iterate != NULL)
    {
        if (iterate->character == c)
        {
            return 1;
        }

        iterate = iterate->next;
    }

    return 0;
}

void insertLinkedNode(LList *list, char c)
{
    // intialize new Node
    LinkedNode *newNode = (LinkedNode *)malloc(sizeof(LinkedNode));
    newNode->character = c;
    newNode->next = NULL;
    newNode->instances = 1;
    if (list->front == NULL)
    {
        newNode->previous = NULL;
        list->front = newNode;
        list->rear = newNode;
        list->count = 1;
        return;
    }

    list->rear->next = newNode;
    newNode->previous = list->rear;
    list->count = list->count + 1;
    list->rear = newNode;
}
void deleteLinkedNode(LList *list, int index)
{
    if(index == 1){
        LinkedNode *dummy = list->front;
        list->front = list->front->next;
        free(dummy);
        return;
    }
    for(int i = 0; i < index; i++){
        
    }
}
// Method to sort linkedList
void sortLinkedList(LList *list)
{
    // insertion sort with integers
    /*
    for(int i = 1; i < 10; i++){
        printf("Current Value: %d\n",*(arr + i));
        int j = i -1;
        int dummy = *(arr + i);
        while(j >= 0 && *(arr + j) >= *(arr+i)){
            *(arr+j + 1) = *(arr + j);
            j--;
        }
        *(arr + j + 1) =  dummy;
    }
    */
    LinkedNode *iterate = list->front->next;
    if (iterate == NULL)
    {
        return;
    }

    while (iterate != NULL)
    {
        LinkedNode *sortedIterator = iterate->previous;
        int current_instances = iterate->instances;
        char current_character = iterate->character;
        while (sortedIterator != NULL && sortedIterator->instances > current_instances)
        {
            sortedIterator->next->instances = sortedIterator->instances;
            sortedIterator->next->character = sortedIterator->character;
            sortedIterator = sortedIterator->previous;
        }

        if (sortedIterator == NULL)
        {
            list->front->instances = current_instances;
            list->front->character = current_character;
        }
        else
        {
            sortedIterator->next->instances = current_instances;
            sortedIterator->next->character = current_character;
        }

        iterate = iterate->next;

        // put value in next node
    }
}
// Method to increment the count of character c by 1
void updateList(LList *list, char c)
{
    LinkedNode *iterate = list->front;
    while (iterate != NULL)
    {
        if (iterate->character == c)
        {
            iterate->instances = iterate->instances + 1;
            return;
        }

        iterate = iterate->next;
    }
}

// Function to print the characters and corresponding frequencies
void printInfo(LList *list)
{

    LinkedNode *iterate = list->front;
    while (iterate != NULL)
    {
        if (iterate->character == 32)
        {
            printf("Char: space, Freqeuency: %d\n", iterate->instances);
        }
        else if (iterate->character == 10)
        {
            printf("Char: End of Line/newline, Freqeuency: %d\n", iterate->instances);
        }
        else
        {
            printf("Char: %c, Freqeuency: %d\n", iterate->character, iterate->instances);
        }

        iterate = iterate->next;
    }
}
LList *readFile(FILE *file, char *path, LList *list)
{
    // Open file to read
    file = fopen(path, "r");
    if (file == NULL)
    {
        printf("Can not open file\n");
        return NULL;
    }

    printf("Success!");
    printf("\n");
    char character;

    // Read File while end of file has not been reached
    while ((character = getc(file)) != EOF)
    {
        // count instance of each character using linkedList
        int result = hasInstance(list, character);

        if (result == 1)
        {
            updateList(list, character);
        }
        else
        {
            // create new node in linked list and set instance value to 1
            insertLinkedNode(list, character);
            // indicate char is unique
            printf("Unique: %c\n", character);
        }
    }

    printInfo(list);
    return list;
}
