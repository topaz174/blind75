/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
class Solution {
private:
    struct TrieNode {
        TrieNode* links[26] = {nullptr};
        string finalWord = "";
    };
    TrieNode* root = new TrieNode();

    vector<string> found;
    // unordered_set<string> foundSet;
    
    int rows;
    int cols;

    void createTrie(vector<string>& words) {
        for (string word : words) {
            TrieNode* curr = root;

            for (char c : word) {
                if (curr->links[c - 'a'] == nullptr) {
                    curr->links[c - 'a'] = new TrieNode();
                }

                curr = curr->links[c - 'a'];
            }

            curr->finalWord = word;
        }
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        createTrie(words);

        rows = board.size();
        cols = board[0].size();

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (root->links[board[row][col] - 'a']) {
                    // cout << board[row][col] << " ---------------------------------------------------" << endl;
                    findWordsHelper(board, root, row, col);
                }
            }
        }

        return found;
    }

    void findWordsHelper(vector<vector<char>>& board, TrieNode* curr, int row, int col) {
        // cout << row << " " << col << " ";
        if (row >= rows || col >= cols || row < 0 || col < 0 || board[row][col] == '!' ) {
            // cout << "invalid" << endl;
            return;
        }

        char currChar = board[row][col];

        curr = curr->links[currChar - 'a'];

        if (curr == nullptr) {
            // cout << "null" << endl;;
            return;
        }

        // cout << currChar << endl;

        board[row][col] = '!';

        if (curr->finalWord != "") {
            // cout << "FOUND" << endl;
            found.push_back(curr->finalWord);
            curr->finalWord = "";
        }

        findWordsHelper(board, curr, row, col - 1); // left
        findWordsHelper(board, curr, row - 1, col); // up
        findWordsHelper(board, curr, row, col + 1); // right
        findWordsHelper(board, curr, row + 1, col); // down
        

        board[row][col] = currChar;
    }
};
// @lc code=end

