#include <stdio.h>
#include "ArrayList.h"

int main() {
	int arr[4] = { 1,2,3,4 };
	struct node* arrList = newArrayList(arr, 4, sizeof(int));
	printf("%d", *((int*)getData(arrList, 0)));
}