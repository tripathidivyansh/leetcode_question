class Solution {
public:
    void getLeafNodes(TreeNode* root, vector<int> &leaves) {
        if (root == NULL) return;

        
        if (root->left == NULL && root->right == NULL) {
            leaves.push_back(root->val);
            return;
        }
        getLeafNodes(root->left, leaves);
        getLeafNodes(root->right, leaves);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL) {
            return true;
        }
        if ((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL)) {
            return false;
        }
        vector<int> leaf1, leaf2;
        getLeafNodes(root1, leaf1);
        getLeafNodes(root2, leaf2);

        return leaf1 == leaf2;
        
    }
};
