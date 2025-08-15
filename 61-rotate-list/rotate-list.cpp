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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        vector<int>ans;
        if(!head) return NULL;
        ListNode* temp = head;

        while(temp){
            ans.push_back(temp->val);
            temp = temp->next;
        }
        int n = ans.size();
        k = k %n;
        reverse(ans.begin(), ans.end());
        reverse(ans.begin(), ans.begin() + k);
        reverse(ans.begin() + k, ans.end());
        temp = head;
        for (int i = 0; i < n; i++) {
            temp->val = ans[i];
            temp = temp->next;
        }
        return head;
    }
};