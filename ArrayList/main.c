#include <stdio.h>
#include "ArrayList.h"

int main() {
	int arr[4] = { 1,2,3,4 };
	struct node* arrList = newArrayList(arr, 0);
	printf("%d", getValue(arrList, 0));
}