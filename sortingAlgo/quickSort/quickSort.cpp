#include <iostream>
 
using namespace std;
 
void quick_sort(int[],int,int);
int partition(int[],int,int);
 
int main()
{
    int a[] ={90,23,101,45,65,23,67,89,34,23} ;  // sample test case to demo the quicksort function 
    int n = 10;      
    quick_sort(a,0,n-1);
    cout<<"\nArray after sorting:";
    
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    
    return 0;        
}
 
void quick_sort(int a[],int l,int u)    // l is the first element and u is the last element with a being the array 
{
    int j;
    if(l<u)
    {
        j=partition(a,l,u);
        quick_sort(a,l,j-1);
        quick_sort(a,j+1,u);
    }
}
 
int partition(int a[],int l,int u)
{
    int v,i,j,temp;
    v=a[l];
    i=l;
    j=u+1;
    
    do
    {
        do
            i++;
            
        while(a[i]<v&&i<=u);
        
        do
            j--;
        while(v<a[j]);
        
        if(i<j)                       //swapping implement in the following three lines
        { 
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);
    
    a[l]=a[j];
    a[j]=v;
    
    return(j);
}