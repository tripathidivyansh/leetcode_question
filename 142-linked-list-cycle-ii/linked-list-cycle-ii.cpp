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
        if(head == NULL) return NULL;
        ListNode* Slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){

            Slow = Slow->next;
            fast = fast->next->next;
            if(Slow == fast){
                Slow = head;
                while(Slow != fast){
                    Slow = Slow->next;
                    fast = fast->next;
                }
                return Slow;
            }
        }
        return NULL;
    }
};