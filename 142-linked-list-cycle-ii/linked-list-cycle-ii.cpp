/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* Slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){

            Slow = Slow->next;
            fast = fast->next->next;
            if(Slow == fast){
                break;
            }
        }
        if(Slow != fast) return NULL;
        ListNode* p = head;
        while(p != Slow) {
             p = p->next;
            Slow = Slow->next;
        }
        return p;
    }
};























