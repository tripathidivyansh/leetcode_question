class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, unsigned long long>> q;  

        q.push({root, 0});
        long long maxWidth = 0;
        while (!q.empty()) {

            int size = q.size();
            unsigned long long left = q.front().second;
            unsigned long long right = q.back().second;
            maxWidth = max(maxWidth, (long long)(right - left + 1));
            while (size--) {
                auto [node, index] = q.front();

                q.pop();
                index = index - left;  

                if (node->left)
                    q.push({node->left, 2 * index + 1});
                if (node->right)
                    q.push({node->right, 2 * index + 2});
            }
        }
        return maxWidth;
    }
};

