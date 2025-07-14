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
    int getDecimalValue(ListNode* head) {
        string ans = "";
        ListNode* temp = head;
        while(temp != NULL){

            ans += (temp->val + '0');
            temp = temp->next;
        }
        int ans1 = 0;
        for(char ch : ans){
            ans1 = ans1 * 2 + (ch - '0');
        }
        return ans1;
    }
};