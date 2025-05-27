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

    void solve(TreeNode* root, int level, int &maxDeafth, int &leftVal){
        if(root == NULL){
            return;
        }
        if(level > maxDeafth){
            maxDeafth = level;
            leftVal = root->val;
        }
        solve(root->left, level+1, maxDeafth, leftVal);
        solve(root->right, level+1, maxDeafth, leftVal);
    }
    int findBottomLeftValue(TreeNode* root) {
        int maxDeafth = -1;
        int leftVal = 0;
        solve(root, 0, maxDeafth, leftVal);
        return leftVal;
    }
};