class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max_streak = 0;

        unordered_set<int> nums_set;

        for (int i = 0; i < nums.size(); ++i) {
            nums_set.insert(nums[i]);
        }

        int streak_sum = 0;

        for (const int& element : nums_set) {
            int curr = element;

            if (nums_set.count(curr - 1)) { // if my predecessor is in the hash set, skip me
                continue;
            }


            int bound = curr + nums.size() - streak_sum;
            int streak = 0;

            for (curr; curr < bound; curr++) {
                if (nums_set.count(curr)) {
                    streak++;
                }
                else {
                    break;
                }
            }

            streak_sum++;

            if (streak > max_streak) {
                max_streak = streak;
            }
        }
        return max_streak;
    }
};
