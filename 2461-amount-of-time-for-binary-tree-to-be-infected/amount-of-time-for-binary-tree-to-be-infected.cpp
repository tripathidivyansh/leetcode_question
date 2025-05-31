/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* mapParents(TreeNode* root, int start, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        TreeNode* targetNode = nullptr;
        queue<TreeNode*> q;
        q.push(root);
        parentMap[root] = nullptr;

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->val == start) {
                targetNode = curr;
            }
            if (curr->left) {
                parentMap[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parentMap[curr->right] = curr;
                q.push(curr->right);
            }
        }
        return targetNode;
    }
    int burnTree(TreeNode* startNode, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(startNode);
        visited[startNode] = true;
        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool burnedNewNode = false;

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left && !visited[curr->left]) {
                    visited[curr->left] = true;
                    q.push(curr->left);
                    burnedNewNode = true;
                }
                if (curr->right && !visited[curr->right]) {
                    visited[curr->right] = true;
                    q.push(curr->right);
                    burnedNewNode = true;
                }
                TreeNode* parent = parentMap[curr];
                if (parent && !visited[parent]) {
                    visited[parent] = true;
                    q.push(parent);
                    burnedNewNode = true;
                }
            }
            if (burnedNewNode) time++;
        }
        return time;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        TreeNode* startNode = mapParents(root, start, parentMap);
        return burnTree(startNode, parentMap);
    }
};
