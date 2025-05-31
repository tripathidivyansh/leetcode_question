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
    void createMapping(vector<int>& inorder, unordered_map<int, int>& nodeToIndex) {
        for (int i = 0; i < inorder.size(); i++) {
            nodeToIndex[inorder[i]] = i;
        }
    }

    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int& postIndex, int inorderStart, int inorderEnd, unordered_map<int, int>& nodeToIndex) {
        if (postIndex < 0 || inorderStart > inorderEnd) {
            return nullptr;
        }

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);
        int inorderIndex = nodeToIndex[rootVal];

        root->right = buildTreeHelper(inorder, postorder, postIndex, inorderIndex + 1, inorderEnd, nodeToIndex);
        root->left = buildTreeHelper(inorder, postorder, postIndex, inorderStart, inorderIndex - 1, nodeToIndex);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> nodeToIndex;
        createMapping(inorder, nodeToIndex);
        int postIndex = postorder.size() - 1;
        return buildTreeHelper(inorder, postorder, postIndex, 0, inorder.size() - 1, nodeToIndex);
    }
};
