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
    int Solve(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(Solve(root->left), Solve(root->right));
    }
    int maxDepth(TreeNode* root) {
        return Solve(root);
    }
};
