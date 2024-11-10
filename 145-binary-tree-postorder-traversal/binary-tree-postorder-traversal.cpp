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
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int>result;
//         postorderTraversal(root, result);
//         return result;
//     }
// private:
//     void postorderTraversal(TreeNode* node, vector<int>& result){
//         if(node == NULL){
//             return;
//         }
//         postorderTraversal(node->left, result);
//         postorderTraversal(node->right, result);
//         result.push_back(node->val);
//     }
// };


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>postorder;
        if(root == NULL) return postorder;
        stack<TreeNode*>s1,s2;
        s1.push(root);
        while(!s1.empty()){
            root = s1.top();
            s1.pop();
            s2.push(root);

            if(root->left != NULL){
                s1.push(root->left);
            }
            if(root->right != NULL){
                s1.push(root->right);
            }
        }
        while(!s2.empty()){
            postorder.push_back(s2.top()->val);
            s2.pop();
        }
        return postorder;
    }
};