class Solution {
public:
    void solve(TreeNode* root, int &Sum, int current) {
        if (root == NULL) return;

        current = current * 10 + root->val;

        if (root->left == NULL && root->right == NULL) {
            Sum += current;
            return;
        }

        solve(root->left, Sum, current);
        solve(root->right, Sum, current);
    }

    int sumNumbers(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int Sum = 0;
        solve(root, Sum, 0);
        return Sum;


    }
};