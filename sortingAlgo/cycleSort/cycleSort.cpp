//cycle sort - Sorts an array in minimum swaps

#include<bits/stdc++.h>
using namespace std;

void cycleSort(int *arr,int n)
{
    for(int i=0;i<n-1;i++)
    {
        int val = arr[i];
        int index = i;
        for(int j=i+1;j<n;j++)
            if(arr[j] < val)
                index++;

	//if the element is in the correct position        
	if(index == i)
            continue;

	//to handle duplicate elements        
	while(val == arr[index])
            index++;

        if(index != i)
            swap(val,arr[index]);
        
        while(index != i)
        {
            index = i;
            for(int j=i+1;j<n;j++)
                if(arr[j] < val)
                    index++;
            while(val == arr[index])
                index++;
            if(val != arr[index])
                swap(val,arr[index]);
        }
    }
}
int main()
{
    int arr = {20,30,10,20,70};
    int n = 5;
    cycleSort(arr,n);
}

