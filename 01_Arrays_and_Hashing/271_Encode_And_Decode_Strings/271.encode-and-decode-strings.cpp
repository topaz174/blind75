/*
 * @lc app=leetcode id=271 lang=cpp
 *
 * [271] Encode and Decode Strings
 */

// @lc code=start
class Solution {
public:

    /* 
    ["Hello", "World"] -> "HelloWorld" with encodings
    cant just do Hello#World because strings themselves could have #
    but like how would u do this then
    for any form of encoding within a string it can always be in the original string
    maybe then we take advantage of the maximum size of 200?
    we could pad every string to 200 chars and add the encoding standard from the 201st
    but then the padding char itself could also be in the original string
    and that just doesnt seem like the strat anyway
    FUCK. hmmm
    ok the thing is there are 256 possible characters but length is capped at 200, so theres bound to be an ascii character that isnt used within each string
    ah but it can be used in the next one. so no.
    wait lol what if i just force the first character(s) to be the encoding standard
    so #Hello#World
    if its ["#ello", "World"] we just find a char that isnt in there so like $#ello$World
    oh wait no fuck. again any ascii can be in any string
    ok im thinking then, we create a hashset with all the characters that are in there
    then we take a char that isnt in the hashset
    ok for simplicity lets say the only chars that can exist are abcde
    then for ["ab", "de"]
    set would be {c}
    so "abcde"
    problem is it could be ["ab", "cde"]
    so then u would have to do combinations of characters that arent present wouldnt u
    like ac, ad etc since those two arent found next to eachotehr
    then it would be 
    abaccde
    the decoder would search for ac
    sounds good but how would we know when to check for combinations
    maybe when the size of the set >= 256?
    from there u would go for combos which is 256^2 which is bigger than 100*200 
    so yeah, we dont have to keep going to 3+ thankfully(i hope)
    as for how to tell the decoder its a 2 and not a 1, we put a number at the start: 1 or 2, which is how many chars would be scanned from there until we get to the actual string
    ["ab", "de"]->1cabcde
    ["ab", "cde"]->2acabaccde
    lets do this shit.
    */

    string encode(vector<string>& strs) {

        unordered_set<char> chars;
        char flag = '1';
        string tempStr;
        string res;

        for (int i = 0; i < strs.size(); i++) {
            for (int j = 0; j < strs[i].length(); j++) {
                // on each char, add one to the freq
                chars.insert(strs[i][j]); 
                tempStr += strs[i][j];
            }
        }

        if (chars.size() < 256) {
            char delimiter;

            for (int i = 0; i < 256; i++) {
                char c = static_cast<char>(i);
                
                if (chars.find(c) == chars.end()) { // if the char isnt in the set of all chars, i.e no string had it
                    delimiter = c;
                }

            }

            res = string(1, flag) + string(1, delimiter); // add the encoding standard to the start

            for (int i = 0; i < strs.size(); i++) {
                for (int j = 0; j < strs[i].length(); j++) {
                    res += strs[i][j]; // add each character
                }
                res += delimiter;
            }
        }
            
       
        else {
            string delimiter;
            flag = 2;
        
            for (int i = 0; i < 256; i++) {
                char ci = static_cast<char>(i);

                for (int j = 0; j < 256; j++) {
                    char cj = static_cast<char>(j);
                    string sij = "" + ci + cj;

                    if (tempStr.find(sij) == string::npos) { // if this two characters is not in the string
                        delimiter = sij;
                    }

                }
            }

            res = to_string(flag) + delimiter;

            for (int i = 0; i < strs.size(); i++) {
                for (int j = 0; j < strs[i].length(); j++) {
                    res += strs[i][j]; // add each character
                }
                res += delimiter;
            }

        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;

        if (s[0] == '1') {
            char delimiter = s[1];
            string buf;
            for (int i = 2; i < s.length(); i++) {
                if (s[i] != delimiter) {
                    buf += s[i];
                }
                else {
                    res.push_back(buf);
                    buf = "";
                }
            }
        }
        else {
            string delimiter = s.substr(1, 2);
            string buf;
            for (int i = 3; i < s.length(); i++) {
                if ((i != s.length() - 1) && (s.substr(i, 2) != delimiter)) {
                    buf += s[i];
                }
                else {
                    res.push_back(buf);
                    buf = "";
                    i++;
                }
            }
        }

        return res;

    }
};
// @lc code=end
