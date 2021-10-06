#include <sstream>
#include <iterator>
#include <functional>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
#include <string>
#include <bits/stdc++.h>
#include <type_traits>
#include <utility>
#include <iomanip>
#include <iostream>
/*!
 * This function implements the Radix Sorting Algorithm based on the **less significant digit** (LSD).
 * 
 * @note This is a non-comparison sort algorithm. This version works for any kind of integers.
 *
 * @param v Vector to be sorted.
 */
void radix(std::vector<int> &v) {    
    // the number of digits of max element indicates how many times the main loop will be executed 
    int maxDig = std::to_string(*std::max_element(v.begin(), v.end())).size(); 

    // one bucket for each digit from 0 to 9
    std::array<std::vector<int>, 10> buckets;

    // main loop; maxDig times
    for(int i = 0; i < maxDig; i++) {
        // inter loop; insert each element into its respective bucket depending on which digit position is being analyzed
        std::for_each(v.begin(), v.end(), [&buckets, i](int value){ buckets[(int)(value/std::pow(10, i))%10].push_back(value); });
        
        // ==============================================================
        // What the for_each above does is:
        // --------------------------------------------------------------
        // Assuming value = 123 and that the largest number in the collection has 4 digits.
        // 1st pass: 123/1 = 123; 123 % 10 = 3. buckets[3].push_back(123).
        // 2nd pass: 123/10 = 12; 12 % 10 = 2.  buckets[2].push_back(123).
        // 3rd pass: 123/100 = 1; 1 % 10 = 1.   buckets[1].push_back(123).
        // 4th pass: 123/1000 = 0; 0 % 10 = 0.  buckets[0].push_back(123).
        // ==============================================================
 
        // copy from buckets to the original range
        auto destination = v.begin();
        for(auto &b : buckets) {
            destination = std::copy(b.begin(), b.end(), destination);
            b.clear();
        }
    }
}

/*!
 * Simple print function.
 */
void printV(std::vector<int> v) {  
    for(int i = 0; i < v.size(); i++) std::cout << v[i] << " "; 
    std::cout << std::endl; 
} 

/*!
 * This function separates the main vector into two: one containing negative integers and one containing non-negative integers.
 *
 * @param v Vector with non-negative integers.
 * @param negV Vector with negative integers.
 */
void splitV(std::vector<int> &v, std::vector<int> &negV) {
    for(int i = 0; i < v.size(); i++) {
        if(v[i] < 0) {
            negV.push_back(v[i]);
            v.erase(v.begin() + i);
        }
    }
}

/*!
 * This function converts positive to negative and negative to positive.
 *
 * @param v Vector whose elements will be changed.
 */
void negPos(std::vector<int> &v) {
    for(auto &a : v) {
        a *= -1;
    }
}

/*!
 * This function joinVs two vectors.
 * 
 * @param v Vector with non-negative integers.
 * @param negV Vector with negative integers.
 */
void joinV(std::vector<int> &v, std::vector<int> &negV) {
    // reverses because the original values are negative
    std::reverse(negV.begin(), negV.end()); 
    for(auto &a : negV) v.insert(v.begin(), a);
}


int main() {  
    std::vector<int> v = {23, -10, 20, -11, 12, -6, 7};  
    std::vector<int> negV;
    
    splitV(v, negV);

    negPos(negV);
  
    radix(v);
    radix(negV);  

    negPos(negV);

    joinV(v, negV);
  
    std::cout << "Sorted: ";
    printV(v); 
    
    return 0;  
}  
