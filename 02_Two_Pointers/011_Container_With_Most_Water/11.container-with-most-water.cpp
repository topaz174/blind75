/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        
        int maxArea = 0;

        while (l < r) {
            int currArea = (r - l) * min(height[l], height[r]);

            maxArea = max(currArea, maxArea);
            
            if (height[l] <= height[r]) {
                l++;
            }
            else if (height[l] > height[r]) {
                r--;
            }
        }

        return maxArea;
    }
};
// @lc code=end

