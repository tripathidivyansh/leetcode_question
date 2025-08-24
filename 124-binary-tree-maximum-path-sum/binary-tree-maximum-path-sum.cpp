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
    int Solve(TreeNode* root, long long &maxSum){
        if(root == NULL) return 0;
        int left = max(0, Solve(root->left, maxSum));

        int right = max(0, Solve(root->right, maxSum));
        long long Sum = root->val + left + right;

        maxSum = max(maxSum, Sum);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        long long maxSum = INT_MIN;
        Solve(root, maxSum);

        return maxSum;
    }
};