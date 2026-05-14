/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
       
//         vector<vector<string>> res;        

//         unordered_map<unordered_map<char, int>, vector<string>> m;

//         for (int i = 0; i < strs.size(); i++) { // loop through each string of strs

//             s = strs[i]; // get current string
//             unordered_map<char, int> sm;  // hash map of the string

//             for (int j = 0; j < s.length(); j++) { // for each character in the string
//                 sm[s[i]]++;
//             }

//             m[sm].push_back(s); // add the current string to the vector corresponding to the hash map

//         }

//         for (const auto& pair : myMap) { // loop through the hash map we created
//             res.push_back(pair.second);
//         }

//         return res;

//     }
    
// };
// @lc code=end
