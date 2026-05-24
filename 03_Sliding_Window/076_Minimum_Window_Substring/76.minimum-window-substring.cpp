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
        unordered_map<char, int> freqs;
        unordered_map<char, int> bank;
        int score = 0;

        for (char c : t) {
            freqs[c]++;
            bank[c] = 0;
        }

        for (int r = 0; r < s.size(); ++r) {
            // int currLen = r - l + 1;
            cout << l << " " << r << endl;

            if (freqs.count(s[r]))  {
                // cout << s[r] << ": " << bank[s[r]] << endl; 
                if (bank[s[r]] < freqs[s[r]]) {
                    score++;
                }
                bank[s[r]]++;
            }

            while (score == t.length()) {
                if (r - l + 1 < minLen) {
                    // cout << "currLen: " << currLen << endl;
                    minLen = r - l + 1;
                    minStr = s.substr(l, r - l + 1);
                    cout << "minStr: " << minStr << endl;
                }
                if (freqs.count(s[l])) {
                    if (bank[s[r]] <= freqs[s[r]]) {
                        score--;
                    }

                    freqs[s[l]]--;
                }
                l++;
            }
        }

        return minStr;
    }
};
// @lc code=end

