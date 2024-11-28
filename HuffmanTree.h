#include <stdio.h>
#include<stdlib.h>
#include "HuffmanLinked.h"
#ifndef HuffmanTree
#define HuffmanTree
//Define huffman tree node;
typedef struct node{
    int index;
    unsigned int weight;
    struct node* left;
    struct node* right;
} TREENODE;

typedef struct{
    TREENODE *root;
}TREE;

void createHuffTree(LinkedNode *LList);
void create_weight_node(LinkedNode *first, LinkedNode *second);
#endif