#include <stdio.h>
#include "LinkedList.h"

int main() {
	int arr[4] = { 1,2,3,4 };
	struct node* arrList = newLinkedList(arr, 4, sizeof(int));
	printf("%d\n", *((int*)getData(arrList, 0)));
	printf("%u\n", getLength(arrList));
	deleteNode(arrList, 1, 2);
	printf("%d\n", *((int*)getData(arrList, 1)));
}