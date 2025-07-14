class Solution {
public:
    int solve(Node* root) {
        if (root == NULL) {
            return 0;
        }
        int maxDepthFromChildren = 0;
        for (Node* child : root->children) {
            maxDepthFromChildren = max(maxDepthFromChildren, solve(child));
        }
        return 1 + maxDepthFromChildren;
    }
    int maxDepth(Node* root) {
        return solve(root);
    }
};