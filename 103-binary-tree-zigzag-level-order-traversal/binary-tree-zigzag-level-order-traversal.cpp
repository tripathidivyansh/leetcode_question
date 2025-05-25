class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);

            for (int i = 0; i < size; i++) {
                TreeNode* frontNode = q.front();
                q.pop();

                int index;
                if (leftToRight) {
                    index = i;
                } else {
                    index = size - i - 1;
                }

                level[index] = frontNode->val;

                if (frontNode->left != NULL) {
                    q.push(frontNode->left);
                }
                if (frontNode->right != NULL) {
                    q.push(frontNode->right);
                }
            }
            result.push_back(level);
            leftToRight = !leftToRight;
        }
        return result;
    }
};
