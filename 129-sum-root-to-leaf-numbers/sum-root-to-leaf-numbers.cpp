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
    void solve(int curr, TreeNode* root, int &Sum){
        if(root == NULL) return;
        // curr += root->val;

        curr = curr * 10 + root->val;
        if(root->left == NULL && root->right == NULL){
            Sum += curr;
        }
        solve(curr, root->left, Sum);
        solve(curr, root->right, Sum);
    }
    int sumNumbers(TreeNode* root) {
        int Sum = 0;
        solve(0, root , Sum);

        return Sum; 
    }
};