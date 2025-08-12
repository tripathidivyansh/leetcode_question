/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;

        if(head->next == NULL) return new TreeNode(head->val);
        ListNode* Slow = head;
        ListNode* faSt = head;
        ListNode* prevSlow = NULL;
        while(faSt && faSt->next){
            prevSlow = Slow;
            Slow = Slow->next;
            faSt = faSt->next->next;
        }
        TreeNode* root = new TreeNode(Slow->val);
        prevSlow->next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(Slow->next);
        return root;
    }
};

