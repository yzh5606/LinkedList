#pragma once

struct node;

typedef struct node* LinkedList;

LinkedList newLinkedList(void* pdata, unsigned int size, unsigned int length);
void* getData(LinkedList linkedList, unsigned int index);
unsigned int getLength(LinkedList linkedList);
void deleteNode(LinkedList* plinkedList, unsigned int beginIndex, unsigned int length);
struct node* getNode(LinkedList linkedList, unsigned int index);
void deleteLinkedList(LinkedList* plinkedList);
int addNode(LinkedList* plinkedList, void* pdata, unsigned int beginIndex, unsigned int size, unsigned int length);