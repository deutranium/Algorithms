#include<iostream>
#include<vector>

// binary search implementaion in CPP. 
// Given a sorted array with possible duplicate elements, we need to find the total count of duplicate element as well the first and last index of the same.
using namespace std;

int FirstOccurrence (vector<int> &, int); // function to return the first index of duplicating element to be binary searched
int LastOccurrence (vector<int> &, int);  // function to return the last index of duplicating element to be binary searched

int FirstOccurrence (vector<int> &vec, int n) { 
    
    int beg = 0;                         // beginning index of array
    int end = vec.size() - 1;            // last index of array

    while (beg <= end) {

        int mid = beg + (end-beg)/2;     //finding the middle index after modifying range by changing beg/end indices

        if (vec[mid] == n) {
            if (mid-1 >= 0 and vec[mid-1] == n) { 
               end = mid-1;             // modifying end index to a prior index if that too has our duplicating element then continuing the binary search from beginning to that index
               continue;
            }
            return mid;                 // finally if index mid-1 does not have our duplicating number, "mid" which is the first occuring index is returned.
        }
    
        else if (vec[mid] < n)
            beg = mid + 1;
        else
            end = mid - 1;
    }   
    return -1; 
}

int LastOccurrence (vector<int> &vec, int n) { 
    
    int beg = 0;
    int end = vec.size()-1;

    while (beg <= end) {

        int mid = beg + (end-beg)/2;   //finding the middle index after modifying range by changing beg/end indices

        if (vec[mid] == n) {
            if (mid+1 <= vec.size() and  vec[mid+1] == n) { 
               beg = mid + 1;         // modifying beg index to (index+1)  given index has our duplicating element then continuing the binary search from begindex(mid+1 here) to the end index in pursuit of the last index of duplicating element
               continue;
            }
            return mid;               // finally if index mid+1 does not have our duplicating number, "mid" which is the last occuring index is returned.
        }

        else if (vec[mid] < n)
            beg = mid + 1;  
        else
            end = mid - 1;
    }   
    return -1; 
}

int main()
{
   vector<int> vec = { 1, 2, 3, 4, 8, 8, 8, 8, 11, 11, 12, 13 };  // test case to see a demo output to the code 

   int first_index, last_index, n;
   n = 8;                          // duplicate element to find first last index and total count

   first_index = FirstOccurrence (vec, n); 
   last_index =  LastOccurrence (vec, n); 

   if (first_index == -1 or last_index == - 1) { 
       cout << "Element does not exist" << endl;
   } else {
       cout << "First Occourance of " << n << " is at index : " << first_index << endl;
       cout << "Last Occourance of " << n << " is at index : " << last_index << endl;
       cout << "Total Count : " << last_index - first_index + 1;
   }   
   return 0;
}

// out put to the test case 
// First Occourance of 8 is at index : 4                                                                                       
// Last Occourance of 8 is at index : 7                                                                                        
// Total Count : 4
