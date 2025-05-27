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

    int solve(TreeNode* root, int level, int &maxDeafth, int &leftVal){
        if(root == NULL){
            return 0;
        }
        if(level > maxDeafth){
            maxDeafth = level;
            leftVal = root->val;
        }
        solve(root->left, level+1, maxDeafth, leftVal);
        solve(root->right, level+1, maxDeafth, leftVal);
        return leftVal;
    }

    int findBottomLeftValue(TreeNode* root) {
        int maxDeafth = -1;
        int leftVal = 0;
        return solve(root, 0, maxDeafth, leftVal);
        
    }
};