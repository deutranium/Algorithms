#include <stdio.h>



// The below function module implements binary_search functionality in an iterative manner.
// If the element is found then it returns the index otherwise -1;
int binary_search(int arr[],int l,int r,int x){
	while(l<=r){

		// This way of calculating mid removes the chances of overflow with respect to the size of integer.
		int mid=l+(r-l)/2;
		if(arr[mid] == x)
			return mid;
		else if(arr[mid]<x)
			l=mid+1;
		else
			r=mid-1;


	}
	return -1;
}

/* 

The below functionality finds the lower_bound of an element in an array.

Lower_bound returns the index of first occurrence of an element if the element is present in the array.
If the element is not present in the array, then returns the index of element just greater than the given element.
If the index returned is same as the length of the array,
then it means the element given is greater than all the elements in the array

*/


int lower_bound(int arr[],int l,int r,int x){
	while(l<=r){
		int mid=l+(r-l)/2;
		
		if(arr[mid]>=x)
			r=mid;
		else
			l=mid+1;
		if(l==r)
			break;
	}
	return l;

}


/*
The below functionality finds the upper_bound of an element in an array.

Upper_bound returns the index of the next greater element present than the element x passed as in input.
If the output is the length of the array, it means that the upper_bound element is not present in the array
*/

int upper_bound(int arr[],int l,int r,int x){
	while(l<=r){
		int mid=l+(r-l)/2;
		
		if(arr[mid]<=x)
			l=mid+1;
		else
			r=mid;
		if(l==r)
			break;
	}
	return l;

}

/*
The below functionality implements floor functionality, i.e 
it returns the array element less than or equal to the input x.
*/


int floor_(int arr[],int l,int r,int x){
	int res=-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(arr[mid]==x)
            return mid;
        else if(arr[mid]<x){
            l=mid+1;
            res=mid;
        }
        else{
            r=mid-1;
            
        }
            
    }
    return res;
}


/*
The below functionality implements ceil functionality, i.e 
it returns the array element greater than or equal to the input x.
*/


int ceil_(int arr[],int l,int r,int x){
	int res=-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(arr[mid]==x)
            return mid;
        else if(arr[mid]>x){
            r=mid-1;
            res=mid;
        }
        else{
            l=mid+1;
            
        }
            
    }
    return res;
}



int main(){

	printf("Enter the number of elements in the array\n");
	int n;
	scanf("%d",&n);

	int arr[n];

	int a;
	printf("Enter the elements of the array in sorted manner\n");
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		arr[i]=a;
	}
	int choice;
	int x;


	while(1){
	printf("Please enter the number to be operated upon(ex. to be searched)\n");
	
	scanf("%d",&x);

	
	printf("Please enter the functionality you want to be operated upon\n");
	printf("1 for binary_search\n");
	printf("2 for lower_bound\n");
	printf("3 for upper_bound\n");
	printf("4 for ceil\n");
	printf("5 for floor\n");
	printf("6 to exit\n");
	scanf("%d",&choice);


	if(choice == 1){

	int index=binary_search(arr,0,n-1,x);
	if(index == -1)
		printf("The element %d is not present in the array\n", x);
	else
		printf("The element %d is present at index %d of the array\n", x,index);

	printf("*************************************************\n");
	printf("\n");
	
	}
	else if(choice == 2){
		int index=lower_bound(arr,0,n-1,x);
		
		printf("The Lower_bound of the element %d in the array is %d\n", x,index);
		printf("*************************************************\n");
		printf("\n");

	}
	else if(choice == 3){
		int index=upper_bound(arr,0,n-1,x);
		printf("The Upper_bound of the element %d in the array is %d\n", x,index);
		printf("*************************************************\n");
		printf("\n");
		
	}
	else if(choice == 4){
		int index=ceil_(arr,0,n-1,x);
		if(index == -1 || index==n)
			printf("The ceil of the array is not present in the array\n");

		else
			printf("The ceil of the element %d in the array is %d\n", x,arr[index]);
		printf("*************************************************\n");
		printf("\n");
	}
	else if(choice == 5){
		int index=floor_(arr,0,n-1,x);

		if(index == -1)
			printf("The floor of the element is not present in the array\n");
		else
			printf("The floor of the element %d in the array is %d\n", x,arr[index]);
		printf("*************************************************\n");
		printf("\n");
	}

	else if(choice == 6){
		printf("Bubyee\n");
		break;
	}
	else{
		printf("Please provide a valid choice\n");
	}
}

	return 0;
	}

