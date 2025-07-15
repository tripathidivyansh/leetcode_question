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
    void solve(int level, TreeNode* root, vector<int>&ans){
        if(root == NULL) return;
        if(level == ans.size()){

            ans.push_back(root->val);
        }
        solve(level + 1, root->right, ans);
        solve(level + 1, root->left, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        solve(0, root, ans);

        return ans;
    }
};