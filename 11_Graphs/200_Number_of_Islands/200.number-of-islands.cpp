/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */
//12:45a

// @lc code=start
class Solution {
private:
    int count;
public:
    int numIslands(vector<vector<char>>& grid) {
        for (int r = 0; r < grid.size(); r++)  {
            for (int c = 0; c < grid.size(); c++)  {
                if (grid[r][c] == '1') {
                    dfs()
                    count++;
                }
            }
        }

        return count;
    }

    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (grid[r][c] == '0' || grid[r][c] == 'X') {
            return;
        }

        grid[r][c] == 'X';

        dfs(grid, r, c - 1);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r + 1, c);
    }

};
// @lc code=end

