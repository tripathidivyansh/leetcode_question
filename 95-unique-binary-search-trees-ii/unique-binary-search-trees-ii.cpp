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
    vector<TreeNode*> Solve(int Start, int end){
        if(Start > end) return {NULL};
        if(Start == end){

            TreeNode* root = new TreeNode(Start);
            return {root};
        }
        vector<TreeNode*>reSult;
        for(int i = Start; i<=end; i++){
            vector<TreeNode*> leftbSt = Solve(Start, i-1);
            vector<TreeNode*> rightbSt = Solve(i+1, end);
            for(TreeNode* leftRoot : leftbSt){
                for(TreeNode* rightRoot : rightbSt){
                    TreeNode* root = new TreeNode(i);
                    root->left = leftRoot;
                    root->right = rightRoot;
                    reSult.push_back(root);
                }
            }
        }
        return reSult;
    }
    vector<TreeNode*> generateTrees(int n) {
        return Solve(1, n);
    }
};




