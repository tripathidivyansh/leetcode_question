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


// class Solution {
// private:
//     int height(struct TreeNode* node) {
//         if (node == NULL) {
//             return 0;
//         }
//         int left = height(node->left);
//         int right = height(node->right);
//         return max(left, right) + 1;
//     }
// public:
//     bool isBalanced(TreeNode* root) {
//         if (root == NULL) {
//             return true;
//         }
//         bool leftBalanced = isBalanced(root->left);
//         bool rightBalanced = isBalanced(root->right);
//         bool heightDiff = abs(height(root->left) - height(root->right)) <= 1;
//         return leftBalanced && rightBalanced && heightDiff;
//     }
// };

class Solution {
private:
    int dfsHeight(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }

        int leftHeight = dfsHeight(node->left);
        if (leftHeight == -1) return -1;

        int rightHeight = dfsHeight(node->right);
        if (rightHeight == -1) return -1;

        if (abs(leftHeight - rightHeight) > 1) return -1;

        return max(leftHeight, rightHeight) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }
};