/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
private:
    int currSum;
    vector<int> currSet;
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        combinationSumHelper(0, candidates, target);
        return res;
    }
    void combinationSumHelper(int start, vector<int>& candidates, int target) {
        for (int i = start; i < candidates.size(); i++) {
            currSum += candidates[i];
            currSet.push_back(candidates[i]);

            if (currSum >= target) {
                if (currSum == target) {
                    res.push_back(currSet);
                }
                currSet.pop_back();
                currSum -= candidates[i];
            }

            combinationSumHelper(i, candidates, target);
        }
    }
};
// @lc code=end

