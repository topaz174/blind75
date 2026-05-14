/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        unordered_map<int, int> sm;
        unordered_map<int, int> tm;

        for (int i = 0; i < s.length(); i++) {
            sm[s[i]]++;
        }

        for (int j = 0; j < t.length(); j++) {
            tm[t[j]]++;
        }

        if (sm == tm) {
            return true;
        }
    
        return false;
    }

};
// @lc code=end
