#pragma once

struct node;

typedef struct node* LinkedList;

//pdata: A pointer pointed to the raw data
//size: How much bytes of data should each node contains
//length: How many nodes should a linked list contain
//index: An index number of a single node, the first index number is 0

LinkedList newLinkedList(void* pdata, unsigned int size, unsigned int length);//return NULL if unable to create
void* getData(LinkedList linkedList, unsigned int index);
unsigned int getLength(LinkedList linkedList);
void deleteNode(LinkedList* plinkedList, unsigned int beginIndex, unsigned int length);
struct node* getNode(LinkedList linkedList, unsigned int index);
void deleteLinkedList(LinkedList* plinkedList);
int addNode(LinkedList* plinkedList, void* pdata, unsigned int beginIndex, unsigned int size, unsigned int length);//return 1 if failed to add