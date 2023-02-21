#pragma once

struct node;

struct node* newArrayList(void* data, unsigned int lenth, unsigned int size);
void* getData(struct node* arrayList, unsigned int index);
unsigned int getLenth(struct node* arrayList);