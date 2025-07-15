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
    int solve(TreeNode* root, bool & result){
        if(root == NULL) return true;
        int  l = solve(root->left, result);

        int r = solve(root->right, result);
        if(abs(l - r) > 1){
            result = false;
        }
        return 1 + max(l, r);
    }
    bool isBalanced(TreeNode* root) {
        bool result = true;
        solve(root, result);

        return result;
    }
};