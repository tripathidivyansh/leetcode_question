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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;

        while (!q.empty()) {
            int Size = q.size();
            vector<int> level;


            for (int i = 0; i < Size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (flag == true) {
                    level.insert(level.begin(), node->val);
                }
                if (flag == false) {
                    level.push_back(node->val);
                }

                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
            }

            ans.push_back(level);
            flag = !flag;
        }

        return ans;

    }
};