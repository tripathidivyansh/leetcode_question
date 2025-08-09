class Solution {
public:
    TreeNode* Solve(vector<int>& preorder, vector<int>& inorder, int Start, int end, int &index) {
        if (Start > end) return nullptr;

        int rootVal = preorder[index];
        int pos = Start;
        for (; pos <= end; pos++) {
            if (inorder[pos] == rootVal) break;

        }


        index++; 
        TreeNode* root = new TreeNode(rootVal);
        root->left = Solve(preorder, inorder, Start, pos - 1, index);

        root->right = Solve(preorder, inorder, pos + 1, end, index);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int index = 0;
        
        return Solve(preorder, inorder, 0, n - 1, index);
    }
};
