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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>result;
        postorderTraversal(root, result);
        return result;
    }
private:
    void postorderTraversal(TreeNode* node, vector<int>& result){
        if(node == NULL){
            return;
        }
        postorderTraversal(node->left, result);
        postorderTraversal(node->right, result);
        result.push_back(node->val);
    }
};