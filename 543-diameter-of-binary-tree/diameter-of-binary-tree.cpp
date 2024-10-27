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
private:
    int height(TreeNode* node, int &diameterOfBinaryTree){
        if(node == NULL){
            return 0;
        }
        int leftHeight = height(node->left, diameterOfBinaryTree);
        int rightHeight = height(node->right, diameterOfBinaryTree);

        diameterOfBinaryTree = max(diameterOfBinaryTree, leftHeight + rightHeight);
        return  max(leftHeight, rightHeight) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameterOfBinaryTree = 0;
        height(root, diameterOfBinaryTree);

        return diameterOfBinaryTree;
    }
};