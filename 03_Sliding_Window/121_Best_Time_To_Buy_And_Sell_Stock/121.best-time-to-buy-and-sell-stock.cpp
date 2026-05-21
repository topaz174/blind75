/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */



// @lc code=start

#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int pmin = INT_MAX;
        int pmax = INT_MIN;
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++) {

            if (prices[i] < pmin && i < prices.size() - 1) {
                l = i;
                r = i + 1;

                pmin = prices[i];
                pmax = prices[i + 1];
            }
            else if (prices[i] > pmax) {
                r = i;

                pmax = prices[i];
            }

            int currProfit = prices[r] - prices[l];
            maxProfit = max(maxProfit, currProfit);
        }

        return maxProfit;
    }
};
// @lc code=end

