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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*>St;
        vector<int>ans;

        if(root == NULL) return ans;
        St.push(root);
        while(!St.empty()){
            TreeNode* node = St.top();
            St.pop();
            ans.push_back(node->val);
            if(node->right != NULL) St.push(node->right);
            if(node->left != NULL) St.push(node->left);
        }        
        return ans;
    }
};