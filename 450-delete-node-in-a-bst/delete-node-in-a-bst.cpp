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
    TreeNode* findMin(TreeNode* root) {
        while (root->left != NULL) {
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteval(TreeNode* root, int key) {
        if (root == NULL) {
            return nullptr;
        }
        if (key < root->val) {
            root->left = deleteval(root->left, key);
        } else if (key > root->val) {
            root->right = deleteval(root->right, key);
        } else {
            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            TreeNode* temp = findMin(root->right);
            root->val = temp->val;
            root->right = deleteval(root->right, temp->val);
        }
        return root;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return deleteval(root, key);
    }
};
