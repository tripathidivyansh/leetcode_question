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
    void inorder(TreeNode* root, vector<int>&ans){
        if(root == NULL) return;
        inorder(root->left, ans);

        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    TreeNode* solve(vector<int>&ans, int Start, int end){
        if(Start > end) return NULL;
        int mid = Start + (end-Start) /2;

        TreeNode* newNode = new TreeNode(ans[mid]);
        newNode->left = solve(ans, Start, mid-1);
        newNode->right = solve(ans, mid+1, end);
        return newNode;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>ans;
        inorder(root, ans);
        return solve(ans, 0, ans.size()-1);
    }
};