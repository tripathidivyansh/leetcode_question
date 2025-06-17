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

    void solve(TreeNode* root, int low, int high, vector<int>&ans, int &Sum){
        if(root == NULL){
            return;
        }
        solve(root->left, low, high, ans, Sum);
        ans.push_back(root->val);
        solve(root->right, low, high, ans, Sum);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int>ans;
        int Sum = 0;

        solve(root, low, high, ans, Sum);
        for(int i = 0; i<ans.size(); i++){
            if(ans[i] >= low && ans[i] <= high){
                Sum += ans[i];
            }
        }
        return Sum;
    }
};