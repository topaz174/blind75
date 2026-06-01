/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();

        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] >= nums[l]) {
                if (target >= nums[l] && target <= nums[mid]) {
                    // if target is between start and mid
                    r = mid;
                }
                else {
                    l = mid + 1; // nothing here; look right
                }
            }
            else {
                if (target <= nums[r] && target >= nums[mid]) {
                    // if target is between mid and end
                    l = mid;
                }
                else {
                    r = mid - 1; // look left
                }

            }
        }

        return -1;
    }
};
// @lc code=end

