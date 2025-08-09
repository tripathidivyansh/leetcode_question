/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

public:
    unordered_map<TreeNode*, TreeNode*> parent;
    void inorder(TreeNode* root) {
        if (!root) return;
        if (root->left) {
            parent[root->left] = root;
            inorder(root->left);
        }
        if (root->right) {

            parent[root->right] = root;
            inorder(root->right);
        }
    }
    void BFS(TreeNode* target, int k, vector<int>& result) {
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<TreeNode*> visited;
        visited.insert(target);
        
        int level = 0;
        while (!q.empty()) {
            int n = q.size();
            if (level == k) break;
            while (n--) {

                TreeNode* node = q.front();
                q.pop();
                if (node->left && !visited.count(node->left)) {
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if (node->right && !visited.count(node->right)) {
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if (parent.count(node) && !visited.count(parent[node])) {
                    q.push(parent[node]);
                    visited.insert(parent[node]);

                }
            }
            level++;
        }
        while (!q.empty()) {

            result.push_back(q.front()->val);
            q.pop();
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        inorder(root);        
        BFS(target, k, result); 
        return result;

    }
};
