class Solution {
private:
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.empty()) return true;

        vector<vector<int>> neighbors(n);
        vector<int> visited(n, 0);
        int count = 0;

        for (vector<int> pair : edges) {
            neighbors[pair[0]].push_back(pair[1]);
            neighbors[pair[1]].push_back(pair[0]);
        }

        if (hasCycle(edges[0][0], -6969, neighbors, visited, count)) {
            return false;
        }

        if (count != n) {
            return false;
        }

        return true;
    }

    bool hasCycle(int node, int prev, vector<vector<int>>& neighbors, vector<int> visited, int& count) {
        if (visited[node] == 1) {
            return true;
        }

        ++count;
        visited[node] = 1;

        for (int neighbor : neighbors[node]) {
            if (neighbor != prev && hasCycle(neighbor, node, neighbors, visited, count)) {
                return true;
            }
        }

        return false;
    }
}