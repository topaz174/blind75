/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < (int)nums.size(); ++i) {
            if (i != 0 && nums[i] == nums[i - 1]) { // skip duplicate outers
                continue;
            }

            int target = -nums[i];

            int l = i + 1;
            int r = (int)nums.size() - 1;

            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    res.push_back({nums[i], nums[l], nums[r]});

                    // move both in until new
                    int prev_l = nums[l];
                    int prev_r = nums[r];
                    while (l < r && nums[l] == prev_l) l++;
                    while (l < r && nums[r] == prev_r) r--;
                }
                else if (nums[l] + nums[r] > target) {
                    r--;
                }
                else if (nums[l] + nums[r] < target) {
                    l++;
                }
            }
        }
        return res;
    }
};
// @lc code=end