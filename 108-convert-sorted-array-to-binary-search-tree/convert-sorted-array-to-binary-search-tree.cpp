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
    TreeNode* solve(vector<int>&nums, int Start, int end){
        if(Start > end) return NULL;
        int mid = Start + (end-Start) /2;

        TreeNode* newNode = new TreeNode(nums[mid]);
        newNode->left = solve(nums, Start, mid-1);
        newNode->right = solve(nums, mid+1, end);
        return newNode;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }
};