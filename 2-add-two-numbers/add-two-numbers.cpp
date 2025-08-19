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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;;
        ListNode* temp1 = l1;

        ListNode* temp2 = l2;
        int carray = 0;
        while(temp1 != NULL || temp2 != NULL){
            int Sum = carray;
            if(temp1) Sum += temp1->val;
            if(temp2) Sum += temp2->val;
            ListNode* newNode = new ListNode(Sum % 10);
            carray = Sum / 10;
            curr->next = newNode;
            curr = curr->next;
            if(temp1) temp1 = temp1->next;
            if(temp2) temp2 = temp2->next;
        }
        if(carray){
            ListNode* newNode = new ListNode(carray);
            curr->next = newNode;
        }
        return dummy->next;
    }
};






