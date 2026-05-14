/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
#include <cctype>
#include <ctype.h> 
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        
        int f = 0;
        int b = s.length() - 1;

        while (f < b) {
            char front;
            char back;

            do {
                front = tolower(s[f]);
                f++;
                cout << front << " ";
            } while (!isalnum(front) && (f < s.length()));

            do {
                back = tolower(s[b]);
                b--;
                cout << back << "\n";
            } while (!isalnum(back) && (b >= 0));

            if (!isalnum(front)) {
                front = '\0';
                back = '\0';
            }

            if (front != back) {
                return false;
            }

        }
        return true;
    }
};
// @lc code=end

