/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;

        for (int i = 0; i < nums.size(); i++) {
            int dist = target - nums[i];
            if (m.find(dist) != m.end()) { // if dist is in the map
                return {m[dist], i};
// @lc code=end
