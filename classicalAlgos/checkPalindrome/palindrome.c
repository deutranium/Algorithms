#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Function to check if a string is palindrome.
 * @param s string to check.
 * @return true if the string is palindrome; false otherwise.
 */ 
bool checkPalindrome(const char *s) {
    int front = 0;                 // Index pointing to the first character of the string
    int back = strlen(s) - 1;     // Index pointing to the last valid character of the string
    
    // Every time front moves forward, back moves back, both towards the center
    while (front < back) {         // Compare front and back 
        if (s[front] != s[back]) {
            return false;
        } 
        front++; 
        back--; 
    }

    return true;
}

/**
 * Driver code.
 */ 
int main() {
    char s[100];  // Assuming the input string has a maximum length of 99 characters
    scanf("%s", s);

    if (checkPalindrome(s)) {
        printf("Palindrome\n");
    } else {
        printf("Not Palindrome\n");
    }
    
    return 0;
}