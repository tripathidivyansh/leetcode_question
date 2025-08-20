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
    ListNode* reverseLL(ListNode* head){
        if(!head || !head->next){
            return head;
        }

        ListNode* last = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;

    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseLL(l1);

        l2 = reverseLL(l2);
        int Sum = 0;
        int carray = 0;
        ListNode* ans = new ListNode();
        while(l1 != NULL || l2 != NULL){
            if(l1){
                Sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                Sum += l2->val;
                l2 = l2->next;
            }
            ans->val = Sum % 10;
            carray = Sum / 10;
            ListNode* newNode = new ListNode(carray);
            newNode->next = ans;
            ans= newNode;
            Sum = carray;
        }
        return carray == 0 ? ans->next : ans;
    }
};





