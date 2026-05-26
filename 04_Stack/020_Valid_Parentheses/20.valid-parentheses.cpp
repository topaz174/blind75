/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> chars;

        for (char c : s) {
            if (c == ')' || c == ']' || c == '}') {
                if (!chars.empty() && c == chars.top()) {
                    chars.pop();
                }
                else {
                    return false;
                }
            }
            else if (c == '(') {
                chars.push(')');
            }
            else if (c == '[') {
                chars.push(']');
            }
            else if (c == '{') {
                chars.push('}');
            }
        }

        return chars.empty();
    }
};
// @lc code=end

