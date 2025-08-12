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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* Slow = head;
        ListNode* prevSlow = NULL;

        ListNode* faSt = head;
        while(faSt != NULL && faSt->next != NULL){
            prevSlow = Slow;
            Slow = Slow->next;
            faSt = faSt->next->next;
        }
        prevSlow->next = Slow->next;
        delete (Slow);

        return head;
    }
};