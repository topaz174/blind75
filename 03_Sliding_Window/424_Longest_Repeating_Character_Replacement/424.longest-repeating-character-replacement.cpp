/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int maxLen = 0;
        char maxChar = ' ';

        unordered_map<char, int> freqs; // character: frequency in window

        for (int r = 0; r < s.length(); ++r) {
            freqs[s[r]]++;

            if (freqs[s[r]] > freqs[maxChar]) {
                maxChar = s[r];
            }

            if (freqs[maxChar] < r - l + 1 - k) {
                freqs[s[l]]--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};
// @lc code=end