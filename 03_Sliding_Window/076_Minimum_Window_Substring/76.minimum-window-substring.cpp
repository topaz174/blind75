/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <string> 

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int minLen = INT_MAX;
        string minStr = "";
        int l = 0;
        int minl = 0;
        int minr = 0;
        unordered_map<char, int> freqs;
        // unordered_map<char, int> bank;

        int score = 0;

        for (char c : t) {
            freqs[c]++;
        }

        for (int r = 0; r < s.size(); ++r) {
            // int currLen = r - l + 1;
            // cout << l << " " << r << endl;

            if (freqs.count(s[r]))  {
                // cout << s[r] << ": " << bank[s[r]] << endl; 
                if (freqs[s[r]] > 0) {
                    score++;
                    // cout << "score++: " << score << endl;
                }
                freqs[s[r]]--;
            }

            while (score == t.length()) {
                if (r - l + 1 < minLen) {
                    // cout << "currLen: " << currLen << endl;
                    minLen = r - l + 1;
                    minr = r;
                    minl = l;
                    // cout << "minStr: " << minStr << endl;
                }
                if (freqs.count(s[l])) {
                    if (freqs[s[l]] >= 0) {
                        score--;
                        // cout << s[r] << ": " << bank[s[r]] << endl; 
                        // cout << "score--: " << score << endl;
                    }

                    freqs[s[l]]++;
                }
                l++;
            }
        }

        if (minLen != INT_MAX) {
            minStr = s.substr(minl, minLen);
        }

        return minStr;
    }
};
// @lc code=end

