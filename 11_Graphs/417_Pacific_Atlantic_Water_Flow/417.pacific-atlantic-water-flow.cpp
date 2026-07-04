/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start
class Solution {
private:
    // map<vector<int>, bool> pacific;
    // map<vector<int>, bool> atlantic;
    int rows;
    int cols    

    vector<vector<int>> res;
public:
    void pacific(vector<vector<int>>& heights, int row, int col, int prevHeight, vector<vector<int>>& pacificMemo) {
        // cout << "pac " << row << " " << col << endl;

        if (row < 0 || col < 0 || row >= rows || col >= cols || pacificMemo[row][col] == 1) {
            return;
        }

        int currHeight = heights[row][col];

        if (currHeight < prevHeight) {
            return;
        }

        pacificMemo[row][col] = 1;

        pacific(heights, row, col - 1, currHeight, pacificMemo);
        pacific(heights, row - 1, col, currHeight, pacificMemo);
        pacific(heights, row, col + 1, currHeight, pacificMemo);
        pacific(heights, row + 1, col, currHeight, pacificMemo);
    }

    void atlantic(vector<vector<int>>& heights, int row, int col, int prevHeight, vector<vector<int>>& pacificMemo) {
        // cout << "atl " << row << " " << col << endl;

        if (row < 0 || col < 0 || row >= rows || col >= cols || heights[row][col] == -1) {
            return;
        }

        int currHeight = heights[row][col];
        // cout << currHeight << endl;

        if (currHeight < prevHeight) {
            return;
        }

        heights[row][col] = -1;

        if (pacificMemo[row][col] == 1) {
            res.push_back({row, col});
        }

        atlantic(heights, row, col - 1, currHeight, pacificMemo);
        atlantic(heights, row - 1, col, currHeight, pacificMemo);
        atlantic(heights, row, col + 1, currHeight, pacificMemo);
        atlantic(heights, row + 1, col, currHeight, pacificMemo);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();

        vector<vector<int>> pacificMemo(rows, vector<int>(cols, -1));
        
        for (int c = 0; c < cols; c++) {
            pacific(heights, 0, c, -1, pacificMemo);
        }
        for (int r = 1; r < rows; r++) {
            pacific(heights, r, 0, -1, pacificMemo);
        }
        for (int c = 0; c < cols; c++) {
            atlantic(heights, rows - 1, c, -1, pacificMemo);
        }
        for (int r = 0; r < rows - 1; r++) {
            atlantic(heights, r, cols - 1, -1, pacificMemo);
        }

        return res;
    }
};
// @lc code=end

