#include<stdio.h>

void merge(int A[], int i1, int j1, int i2, int j2){
	int temp[j2 -i1 + 5];
	int i = i1, j = i2, k = 0;
	
	while(i<=j1 && j<=j2)	
	{
		if(A[i]<A[j])
			temp[k++]=A[i++];
		else
			temp[k++]=A[j++];
	}

	while(j<=j2)	
		temp[k++]=A[j++];

	while(i<=j1)	
		temp[k++]=A[i++];

	for(i=i1,j=0;i<=j2;i++,j++)
		A[i]=temp[j];
}


void mergesort( int Arr[], int i, int j){

	int mid;

	if(i<j){
		mid=(i+j)/2;
		mergesort(Arr, i , mid);
		mergesort(Arr, mid + 1, j);
		merge(Arr, i, mid, mid+1, j);
	}
}

int main(){

	int Arr[] = {345,5435,67,356,6547,74};

	mergesort(Arr, 0, 5);

	for(int i=0 ; i<6 ; i++ ){
		printf("%d ",Arr[i]);
	}
	return 0;
}
