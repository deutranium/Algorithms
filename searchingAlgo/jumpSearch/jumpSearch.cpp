#include <iostream>
#include <vector>
#include <cmath> 
#include <algorithm>

/**
 * Jump search function.
 * 
 * @param v Sorted vector on which the search will be performed.
 * @param x Element to be searched.
 * @return Element index if found; -1 otherwise.
 */ 
int jumpSearch(const std::vector<long int> &v, long int x) {
    int n = v.size(); // number of elements
    int jump = std::sqrt(n); // block size to jump

    // search for the block the element may be in
    int prev = 0;
    while(jump < n && v[jump] <= x) {
        prev = jump; // jump to next block
        jump += std::sqrt(n);
        if(prev >= n) return -1; // vector size exceeded
    }

    // linear search through the block
    while(prev < jump) {
        if(v[prev] == x) return prev; // element found
        prev++;
    }

    return -1; // not found
}

/**
 * Driver code.
 */ 
int main() {
    // sorted vector on which the search will be performed; [0, 30]
    std::vector<long int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30};
    long int x = 7; // element to be searched
    int index = jumpSearch(v, x);

    if(index != -1) std::cout << "Element found at index " << index;
        else std::cout << "Element not found";
    std::cout << std::endl;

    return 0;
}