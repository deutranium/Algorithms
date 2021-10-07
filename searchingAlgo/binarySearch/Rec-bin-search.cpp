#include <bits/stdc++.h>
using namespace std;
 // recursive binary search for sorted array
 bool binse(int arr[],int l,int h,int x)
 {
     if(l>h)
     return -1;
     int mid=l+(h-l)/2; //causes (l+h)/2 overloading so l+(h-l)/2 is preferred 
     if(arr[mid]==x)
     return mid;
     if(arr[mid]>x)
     return binse(arr,l,mid-1,x);
     else 
     return binse(arr,mid+1,h,x);
 }
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int x;
    cin>>x;//number to be searched
    int l=0,h=n-1;//lower limit and higher limit
    int pos=binse(arr,l,h,x);
    if(pos>=0)
    cout<<"The element is found at "<<pos+1;
    else 
    cout<<"The element was not found";
	return 0;
}
