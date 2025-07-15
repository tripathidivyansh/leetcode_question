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
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode* >q;

        q.push(root);
        vector<int>result;
        while(!q.empty()){
            int maxelement = INT_MIN;
            int Size = q.size();
            for(int i = 0; i<Size; i++){
                TreeNode* node = q.front();
                q.pop();

                maxelement = max(maxelement, node->val);
                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
            }
            result.push_back(maxelement);
        }
        return result;
    }
};