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
}