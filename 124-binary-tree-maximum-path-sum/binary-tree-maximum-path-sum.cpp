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
int maxGain(TreeNode* node, int& maxSum){
    if(node == nullptr) return 0;

    int left = max(maxGain(node->left, maxSum), 0);
    int right = max(maxGain(node->right, maxSum), 0);

    int current = node->val + left + right;
    maxSum = max(maxSum, current);

    return node->val + max(left, right);
}
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxGain(root, maxSum);

        return maxSum;
    }
};