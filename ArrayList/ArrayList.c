#include <stdlib.h>

struct node {
	int value;
	struct node* next;
};

struct node* newArrayList(int arr[], unsigned int lenth) {
	struct node* arrayList;
	struct node* thisNode;
	struct node* previousNode;
	// first node
	if (lenth == 0) {
		return NULL;
	}
	thisNode = (struct node*)calloc(1, sizeof(struct node));
	if (thisNode == NULL) {
		return NULL;
	}
	(*thisNode).value = arr[0];
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
			(*thisNode).value = arr[i];
			previousNode = thisNode;
		}
	}
	return arrayList;
}

int getValue(struct node* arrayList, unsigned int index) {
	struct node* selectedNode = arrayList;
	for (unsigned int i = 0; i < index; i++) {
		selectedNode = (*selectedNode).next;
	}
	return (*selectedNode).value;
}