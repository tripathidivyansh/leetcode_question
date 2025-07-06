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
class BSTIterator {
public:
    vector<int>inorder;
    int index = 0;
    BSTIterator(TreeNode* root) {
        inordertraverSal(root);
    }
    void inordertraverSal(TreeNode* root){
        if(root == NULL){
            return;
        }
        inordertraverSal(root->left);
        inorder.push_back(root->val);
        inordertraverSal(root->right);
    }
    int next() {
        return inorder[index++];
    }
    
    bool hasNext() {
        return index < inorder.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */