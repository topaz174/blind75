/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
private:
    vector<int> currSet;
    vector<vector<int>> res;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        subsetsHelper(0, nums);
        return res;
    }
    void subsetsHelper(int idx, vector<int>& nums) {
        for (int i = idx; i < nums.size(); i++) {
            currSet.push_back(nums[idx]);
            subsetsHelper(idx + 1, nums);
            res.push_back(currSet);
            cout << currSet.back() << endl;
            currSet.pop_back();
        }
    }
}
// @lc code=end

