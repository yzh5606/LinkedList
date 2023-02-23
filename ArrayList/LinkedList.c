#include <stdlib.h>
#include "LinkedList.h"

struct node {
	void* data;
	struct node* next;
};

struct node* newLinkedList(void* data, unsigned int length, unsigned int size) {
	struct node* linkedList;
	struct node* thisNode;
	struct node* previousNode;
	char* reader = (char*)data;
	// first node
	if (length == 0) {
		return NULL;
	}
	thisNode = (struct node*)calloc(1, sizeof(struct node));
	if (thisNode == NULL) {
		return NULL;
	}
	(*thisNode).data = calloc(1, size);
	if ((*thisNode).data == NULL) {
		deleteLinkedList(thisNode);
		return NULL;
	}
	for (unsigned int i = 0; i < size; i++) {
		char* writer = (char*)(*thisNode).data;
		*(writer + i) = *reader;
		reader++;
	}
	previousNode = thisNode;
	linkedList = thisNode;
	// else nodes
	if (length > 1) {
		for (unsigned int i = 1; i < length; i++) {
			thisNode = (struct node*)calloc(1, sizeof(struct node));
			if (thisNode == NULL) {
				deleteLinkedList(linkedList);
				return NULL;
			}
			(*previousNode).next = thisNode;
			(*thisNode).data = calloc(1, size);
			if ((*thisNode).data == NULL) {
				deleteLinkedList(linkedList);
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
	return linkedList;
}

void* getData(struct node* linkedList, unsigned int index) {
	return (*(getNode(linkedList, index))).data;
}

unsigned int getLength(struct node* linkedList) {
	unsigned int length = 0;
	struct node* currentNode = linkedList;
	while (currentNode != NULL) {
		length++;
		currentNode = (*currentNode).next;
	}
	return length;
}

void deleteNode(struct node* linkedList, unsigned int beginIndex, unsigned int length) {
	struct node* previousNode = NULL;
	struct node* currentNode = linkedList;
	if (beginIndex != 0) {
		previousNode = getNode(linkedList, beginIndex - 1);
		currentNode = (*previousNode).next;
	}
	for (unsigned int i = 0; i < length; i++) {
		struct node* nextNode = (*currentNode).next;
		free((*currentNode).data);
		free(currentNode);
		currentNode = nextNode;
	}
	if (previousNode != NULL) {
		(*previousNode).next = currentNode;
	}
}

struct node* getNode(struct node* linkedList, unsigned int index) {
	struct node* selectedNode = linkedList;
	for (unsigned int i = 0; i < index; i++) {
		selectedNode = (*selectedNode).next;
	}
	return selectedNode;
}

void deleteLinkedList(struct node* linkedList) {
	struct node* currentNode = NULL;
	struct node* nextNode = linkedList;
	do {
		currentNode = nextNode;
		nextNode = (*currentNode).next;
		if ((*currentNode).data != NULL) {
			free((*currentNode).data);
		}
		free(currentNode);
	} while (nextNode != NULL);
}
