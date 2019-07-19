#include <stdio.h>


int search(char* arr[], int lgt, char* x);

int main(void) {

	//Sample input
	char* arr[] = {"a", "b", "c", "d"};
	char* x = "b";


	int lgt = sizeof(arr)/sizeof(arr[0]);
	printf("%i\n", search(arr, lgt, x));
}


int search(char* arr[], int lgt, char* x) {
	for(int i = 0; i < lgt; i++){
		if (arr[i] == x){
			return i;
		}
	}
	return -1;
}
