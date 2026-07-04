class Solution {
private:
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> leaders(n, -1);
        int count = n;

        for (vector<int>& pair : edges) {
            int leader0 = leader(pair[0], leaders);
            int leader1 = leader(pair[1], leaders);

            if (leader0 == -1) {
                leaders[pair[0]] = pair[0];
            }
            if (leader1 == -1) {
                leaders[pair[1]] = pair[1];
            }
            if (leader0 != leader1) {
                leaders[leader1] = leader0;
                count--;
            }

        }

        return count;
    }
    
    int leader(int node, vector<int>& leaders) {
        int curr = node;

        while (leaders[curr] != -1) {
            curr = leaders[curr];
        }

        return curr;
    }
};
