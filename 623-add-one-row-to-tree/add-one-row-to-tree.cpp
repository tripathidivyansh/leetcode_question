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
    void solve(TreeNode* root, int val, int depth, int current){
        if(root == NULL){
            return;
        }
        if(current == depth-1){
            TreeNode* tempLeft = root->left;
            TreeNode* tempRight = root->right;

            root->left = new TreeNode(val);
            root->left->left = tempLeft;
            root->right = new TreeNode(val);
            root->right->right = tempRight;
            
            return;
        }
        solve(root->left, val, depth, current + 1);
        solve(root->right, val, depth, current + 1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root == NULL){
            return NULL;
        }
        if(depth == 1){
            TreeNode* newroot = new TreeNode(val);
            newroot->left = root;
            return newroot;
        }
        solve(root, val, depth, 1);
        return root;
    }
};