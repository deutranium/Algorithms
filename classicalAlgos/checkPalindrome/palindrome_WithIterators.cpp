#include <iostream>
#include <string>

/**
 * Function to check if a string is palindrome.
 * @param s string to check.
 * @return true if the string is palindrome; false otherwise.
 */ 
bool checkPalindrome(std::string s) {
    auto front = s.cbegin();  // const_iterator pointing to the first character of the string
    auto back = s.cend() - 1; // const_iterator pointing to the last valid character of the string
    
    // every time front moves forward, back moves back, both towards the center
    while(front != back) {    // compare front and back 
        if(*front != *back) { return false; } 
        front++; 
        back--; 
    }

    return true;
}

/**
 * Driver code.
 */ 
int main() {
    std::string s;
    std::cin >> s;

    if(checkPalindrome(s)) { std::cout << "Palindrome" << std::endl; }
        else { std::cout << "Not Palindrome" << std::endl; }
    
    return 0;
}
