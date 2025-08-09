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
    int amountOfTime(TreeNode* root, int start) {
        if (root == nullptr) return -1;

        unordered_map<TreeNode*, TreeNode*> par; 
        par[root] = nullptr;

        queue<TreeNode*> q;
        q.push(root);

        TreeNode* startNode = nullptr;

        // Step 1: BFS to find start node and build parent mapping
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->val == start) {
                startNode = curr;
            }
            if (curr->left) {
                par[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                par[curr->right] = curr;
                q.push(curr->right);
            }
        }

        // Step 2: BFS from start node to simulate burning
        unordered_map<TreeNode*, bool> vis;
        q.push(startNode);
        vis[startNode] = true;

        int ans = -1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode* curr = q.front();
                q.pop();

                // Left child
                if (curr->left && !vis[curr->left]) {
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                // Right child
                if (curr->right && !vis[curr->right]) {
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                // Parent
                if (par[curr] && !vis[par[curr]]) {
                    q.push(par[curr]);
                    vis[par[curr]] = true;
                }
            }
            ans++;
        }

        return ans;
    }
};
