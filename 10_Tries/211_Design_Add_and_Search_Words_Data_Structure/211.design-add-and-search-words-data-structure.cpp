/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start
class WordDictionary {
private:
    struct TrieNode {
        TrieNode* links[26];
        bool isEnd = false;
    };

    TrieNode* root = new TrieNode();

public:
    WordDictionary() {
    }
    
    void addWord(string word) {
        TrieNode* curr = root;

        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            
            if (curr->links[c - 'a'] == nullptr) {
                curr->links[c - 'a'] = new TrieNode();
            }

            curr = curr->links[c - 'a'];
        }

        curr->isEnd = true;
    }
    
    bool search(string word) {
        return searchHelper(word, root, 0);
    }

    bool searchHelper(string word, TrieNode* curr, int idx) {
        char c = word[idx];

        if (curr == nullptr) {
            return false;
        }
        if (idx == word.length() - 1) {
            if (curr->isEnd) {
                return true;
            }
            else {
                return false;
            }
        }

        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (searchHelper(word, curr->links[i], idx + 1)) {
                    return true;
                }
            }
            return false;
        }

        return searchHelper(word, TrieNode* curr->links[c - 'a'], idx + 1);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

