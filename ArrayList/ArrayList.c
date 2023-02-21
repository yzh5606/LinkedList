#include <stdlib.h>
#include "ArrayList.h"

struct node {
	void* data;
	struct node* next;
};

struct node* newArrayList(void* data, unsigned int lenth, unsigned int size) {
	struct node* arrayList;
	struct node* thisNode;
	struct node* previousNode;
	char* reader = (char*)data;
	// first node
	if (lenth == 0) {
		return NULL;
	}
	thisNode = (struct node*)calloc(1, sizeof(struct node));
	if (thisNode == NULL) {
		return NULL;
	}
	(*thisNode).data = calloc(1, size);
	if ((*thisNode).data == NULL) {
		// TODO: fall back
		return NULL;
	}
	for (unsigned int i = 0; i < size; i++) {
		char* writer = (char*)(*thisNode).data;
		*(writer + i) = *reader;
		reader++;
	}
	previousNode = thisNode;
	arrayList = thisNode;
	// else nodes
	if (lenth > 1) {
		for (unsigned int i = 1; i < lenth; i++) {
			thisNode = (struct node*)calloc(1, sizeof(struct node));
			if (thisNode == NULL) {
				// TODO: fall back
				return NULL;
			}
			(*previousNode).next = thisNode;
			(*thisNode).data = calloc(1, size);
			if ((*thisNode).data == NULL) {
				// TODO: fall back
				return NULL;
			}
			for (unsigned int i = 0; i < size; i++) {
				char* writer = (char*)(*thisNode).data;
				*(writer + i) = *reader;
				reader++;
			}
			previousNode = thisNode;
		}
	}
	return arrayList;
}

void* getData(struct node* arrayList, unsigned int index) {
	struct node* selectedNode = arrayList;
	for (unsigned int i = 0; i < index; i++) {
		selectedNode = (*selectedNode).next;
	}
	return (*selectedNode).data;
}

unsigned int getLenth(struct node* arrayList) {
	unsigned int lenth = 0;
	struct node* currentNode = arrayList;
	while (currentNode != NULL) {
		lenth++;
		currentNode = (*currentNode).next;
	}
	return lenth;
}
