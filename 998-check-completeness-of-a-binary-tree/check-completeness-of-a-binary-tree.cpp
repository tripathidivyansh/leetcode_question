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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);

        bool past = false;
        while(!q.empty()){
            TreeNode* root = q.front();
            q.pop();
            if(root == NULL){
                past = true;
            }else{
                if(past == true){
                    return false;
                }
                q.push(root->left);
                q.push(root->right);
            }
        }
        return true;
    }
};