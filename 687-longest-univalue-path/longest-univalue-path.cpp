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
    int Solve(TreeNode* root, int& maxcount){
        if(!root) return 0;
        int leftpath = Solve(root->left, maxcount);

        int rightpath = Solve(root->right, maxcount);
        int left = 0, right = 0;

        if(root->left && root->left->val == root->val){
            left = leftpath + 1;
        }
        if(root->right && root->right->val == root->val){
            right = rightpath + 1;
        }
        maxcount = max(maxcount, left + right);
        return max(left, right);
    }
    int longestUnivaluePath(TreeNode* root) {
        int maxcount = 0;
        Solve(root, maxcount);

        return maxcount;
    }

};

















