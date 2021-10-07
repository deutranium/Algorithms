#include <iostream>
#include <vector> 

/**
 * Interpolation search function.
 * 
 * @param v Sorted vector on which the search will be performed.
 * @param x Element to be searched.
 * @return Element index if found; -1 otherwise.
 */ 
int interpolationSearch(const std::vector<long int> &v, long int x) {
    int lo = 0; // first index
    int hi = v.size() - 1; // last index

    while(lo <= hi && x >= v[lo] && x <= v[hi]) {
        if(lo == hi) {
            if(v[lo] == x) return lo;
            return -1;
        }

        // standard algorithm formula
        // pos is a higher value when the searched element is closer to v[hi]
        // pos is a lower value when the searched element is closer to v[lo]
        int pos = lo + (((double)(hi - lo)/(v[hi] - v[lo])) * (x - v[lo]));

        if(v[pos] == x) return pos; // found

        if(v[pos] < x) lo = pos + 1; // x is in upper part
            else hi = pos - 1; // x is in lower part
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
    int index = interpolationSearch(v, x);

    if(index != -1) std::cout << "Element found at index " << index;
        else std::cout << "Element not found";
    std::cout << std::endl;

    return 0;
}