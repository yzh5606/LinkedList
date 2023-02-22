#pragma once

struct node;

struct node* newLinkedList(void* data, unsigned int length, unsigned int size);
void* getData(struct node* linkedList, unsigned int index);
unsigned int getLength(struct node* linkedList);
void deleteNode(struct node* linkedList, unsigned int beginIndex, unsigned int length);
struct node* getNode(struct node* linkedList, unsigned int index);