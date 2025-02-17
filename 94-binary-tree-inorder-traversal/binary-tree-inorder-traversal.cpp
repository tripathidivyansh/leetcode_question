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
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int>result;
//         inorder(root, result);
//         return result;
//     }
// private:
//     void inorder(TreeNode* node, vector<int>&result){
//         if(node == NULL){
//             return;
//         }
//         inorder(node->left, result);
//         result.push_back(node->val);
//         inorder(node->right, result);

//     }
// };



class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        if (root == NULL) return inorder;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while (!st.empty() || node != NULL) {
            while (node != NULL) {
                st.push(node);
                node = node->left;
            }
            node = st.top();
            st.pop();
            inorder.push_back(node->val);
            node = node->right;
        }
        return inorder;
    }
};

// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         stack<TreeNode*>st;
//         TreeNode* node = root;
//         vector<int>inorder;

//         while(true){
//             if(node != NULL){
//                 st.push(node);
//                 node = node->left;
//             }else{
//                 if(st.empty() == true)  break;
//                 node = st.top();
//                 st.pop();
//                 inorder.push_back(node->val);
//                 node = node->right;

//             }
//         }
//         return inorder;
//     }
// };

