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
    TreeNode* Solve(vector<int>&inorder, vector<int>&postorder, int inStart, int inend, int postStart, int postend){
        if(inStart > inend) return NULL;
        TreeNode* root = new TreeNode(postorder[postend]);

        int pos = inStart;
        for(; pos<= inend; pos++){
            if(inorder[pos] == root->val){
                break;
            }
        }
        int leftSize = pos-inStart;
        int rightSize = inend - pos;
        root->left = Solve(inorder, postorder, inStart, pos-1, postStart, postStart + leftSize-1);
        root->right = Solve(inorder, postorder, pos+1, inend, postend-rightSize, postend-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int inStart = 0, inend = n-1;

        int postStart = 0, postend = n-1;
        return Solve(inorder, postorder, inStart, inend, postStart, postend);
    }

};