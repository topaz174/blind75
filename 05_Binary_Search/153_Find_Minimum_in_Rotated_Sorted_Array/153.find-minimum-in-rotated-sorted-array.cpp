/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = (r + l) / 2;
            cout << l << " " << r << endl;
            cout << mid << endl;
            if (nums[mid] >= nums[l] && nums[mid] < nums[r]) {
                return nums[l];
            }
            else if (nums[mid] > nums[l] && nums[mid] > nums[r]) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }

        return -1;

    }
};
// @lc code=end

