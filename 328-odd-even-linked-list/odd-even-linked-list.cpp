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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return head;
        ListNode* Slow = head;
        ListNode* fast = head->next;

        ListNode* temp = head->next;
        while(fast != NULL && fast->next != NULL){
            Slow->next = Slow->next->next;
            fast->next = fast->next->next;
            Slow = Slow->next;
            fast = fast->next;
        }
        Slow->next = temp;
        return head;
    }
};


























