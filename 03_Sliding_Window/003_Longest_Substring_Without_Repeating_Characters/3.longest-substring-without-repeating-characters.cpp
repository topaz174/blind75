/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start

#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;

        int l = 0;
        int r = 1;
        int maxSize = 1;

        unordered_set<char> chars = {s[l]};

        while (r < (int)s.length()) {
            if (chars.count(s[r])) {
                for (int i = 0; i <= (r - l); ++i) {
                    if (i != 0 && s[l + i - 1] == s[r]) {
                        l += i;
                        break;
                    }
                }
            }
            maxSize = max(maxSize, r - l + 1);

            chars.insert(s[r]);
            r++;
        }

        return maxSize;

    }
};
// @lc code=end

