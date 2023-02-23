#include <stdio.h>
#include "LinkedList.h"

int main() {
	int arr[4] = { 1,2,3,4 };
	LinkedList arrList = newLinkedList(arr, sizeof(int),4);
	printf("%d\n", *((int*)getData(arrList, 0)));
	printf("%u\n", getLength(arrList));
	deleteNode(&arrList, 0, 2);
	printf("%d\n", *((int*)getData(arrList, 0)));
	addNode(&arrList, arr, 0, sizeof(int), 4);
	printf("%d\n", *((int*)getData(arrList, 3)));
	printf("%d\n", *((int*)getData(arrList, 4)));
	addNode(&arrList, arr, 1, sizeof(int), 4);
	printf("%d\n", *((int*)getData(arrList, 0)));
	printf("%d\n", *((int*)getData(arrList, 1)));
	for (int i = 0; i < getLength(arrList); i++) {
		printf("%d", *((int*)getData(arrList, i)));
	}
}