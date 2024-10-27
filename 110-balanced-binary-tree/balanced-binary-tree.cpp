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
    int height(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        int left = height(node->left);
        int right = height(node->right);
        return max(left, right) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        bool leftBalanced = isBalanced(root->left);
        bool rightBalanced = isBalanced(root->right);
        bool diff = abs(height(root->left) - height(root->right)) <= 1;
        return leftBalanced && rightBalanced && diff;
    }
};
