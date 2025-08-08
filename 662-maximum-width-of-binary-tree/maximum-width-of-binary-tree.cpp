class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        long long maxwidth = 0;
        while(!q.empty()){
            long long l = q.front().second;
            long long r = q.back().second;
            maxwidth = max(maxwidth, r - l + 1);
            int n = q.size();

            while(n--) {
                TreeNode* curr = q.front().first;
                long long index = q.front().second - l; 
                q.pop();

                if(curr->left){
                    q.push({curr->left, 2 * index + 1});
                }
                if(curr->right){
                    q.push({curr->right, 2 * index + 2});
                }
            }
        }
        return maxwidth;
    }
};