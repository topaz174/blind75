/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

 // 1:45

// @lc code=start
class Solution {
private:
    struct Node {
        int val;
        vector<Node*> prereqs;
    }

    unordered_map<val, Node*> courses;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // create nodes
        for (vector<int> pair : prerequisites) {
            if (!courses.count(pair[0])) {
                Node* newNode = new Node(pair[0]);
                courses[pair[0]] = newNode;
            }

            courses[pair[0]]->prereqs.push_back(pair[1]);
        }

        unordered_set<Node*> branch;

        for (const auto& course : nodes) {
            if (findCycle(course, branch)) {
                return false;
            }
        }

        return true;
    }

    void dfs(Node* course, unordered_set<Node*>& branch) {
        if (branch.count(course)) {
            return true;
        }

        branch,insert(course);

        for (Node* prereq : prereqs) {
            if (findCycle(prereq)) {
                return true;
            }
        }

        branch.erase(course);
        courses.erase(course);

        return false;
    }
};
// @lc code=end

