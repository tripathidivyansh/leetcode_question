class Solution {
public:
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};

        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);

        int include = root->val + left.second + right.second;
        int exclude = max(left.first, left.second) + max(right.first, right.second);

        return {include, exclude};
    }
    int rob(TreeNode* root) {
        pair<int, int> result = dfs(root);
        return max(result.first, result.second);
    }
};
