class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0); 
        ListNode* large = new ListNode(0); 

        ListNode* smallp = small;
        ListNode* largep = large;
        while (head) {
            if (head->val < x) {
                smallp->next = head;
                smallp = smallp->next;
            } else {
                largep->next = head;
                largep = largep->next;
            }
            
            head = head->next;
        }
        largep->next = NULL;         
        smallp->next = large->next;  
        return small->next; 
    }
};