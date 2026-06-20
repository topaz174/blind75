/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
private:
    int idx;
    int width;
    int height;
    bool found = false;
public:
    bool exist(vector<vector<char>>& board, string word) {
        width = board[0].size();
        height = board.size();

        helper(board, word, 0, 0, 0);

        return found;
    }

    void helper(vector<vector<char>>& board, string word, int x, int y, int prev) {
        if (board[y][x] != word[idx]) {
            return;
        }

        idx++;

        if (idx >= word.size()) {
            found = true;
            return;
        }

        // left
        if (x > 0 && prev != 2) {
            helper(board, word, x - 1, y, 0);
        }
        // up
        if (!found && y > 0 && prev != 3) {
            helper(board, word, x, y - 1, 1);
        }
        // right
        if (!found && x < width - 1 && prev != 0) {
            helper(board, word, x + 1, y, 3);
        }
        // down
        if (!found && y < height - 1 && prev != 1) {
            helper(board, word, x, y + 1, 3);
        }

        idx--;
    }
};
// @lc code=end

