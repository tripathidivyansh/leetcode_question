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
    vector<TreeNode*> Solve(int n){
        if(n % 2 == 0) return {};
        if(n==1){

            TreeNode* root = new TreeNode(0);
            return {root};
        }
        vector<TreeNode*>ans;
        for(int i = 1; i<n; i+= 2){
            vector<TreeNode*> leftbSt = Solve(i);
            vector<TreeNode*> rightbSt = Solve(n-i-1);
            for(TreeNode* left : leftbSt){
                for(TreeNode* right : rightbSt){
                    TreeNode* root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return Solve(n);
    }
};