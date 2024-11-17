#include <iostream>
using namespace std;

/*
    A palindrome is a string that reads the same both forward and backward. For example, the
    string "madam" is a palindrome. Write a program that uses a recursive function to check
    whether a string is a palindrome. Your program must contain a value-returning recursive
    function that returns true if the string is a palindrome and false otherwise. Do not use
    any global variables; use the appropriate parameters.
*/

bool isPalindrome(string str, int start, int end);

int main(){
    string str1 = "madam";
    string str2 = "hello";

    cout << "Is \"" << str1 << "\" a palindrome? " << (isPalindrome(str1, 0, str1.length() - 1) ? "Yes" : "No") << endl;
    cout << "Is \"" << str2 << "\" a palindrome? " << (isPalindrome(str2, 0, str2.length() - 1) ? "Yes" : "No") << endl;
    
    return 0;
}

bool isPalindrome(string str, int start, int end){
    // Base case: all characters checked
    if (start >= end) {
        return true; 
    }
    // Base case: mismatch found
    if (str[start] != str[end]) {
        return false;
    }
    // Recursive case
    return isPalindrome(str, start + 1, end - 1);
}
