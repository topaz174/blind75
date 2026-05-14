# [125]. [Valid Palindrome]
**Category:** Two Pointers | **Difficulty:** 🟢

## 🧠 Brainstorming & Dictation
*   

## ❌ The Graveyard (Failed Attempts)
```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int count = 0;
        string clean_s = "";
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (isalnum((unsigned char) c)) {
                clean_s += tolower(c);
            }
        }
        while (clean_s != "") {
            if (clean_s[0] != clean_s[clean_s.length() - 1]) {
                return false;
            }
            clean_s = clean_s.substr(1, clean_s.length() - 2);
        }
        return true;
    }
};
```
*   **Memory Limit Exceeded (MLE):** Attempted string building and repeatedly using `.substr()` which created too many string copies.

## ✅ The "Aha!" Moment
*   Instead of string building, have the pointers skip over non-alphanumerics directly.
*   Simplified the loop condition from `while ((f != b) && (f < s.length()))` to just `while (f < b)`.
