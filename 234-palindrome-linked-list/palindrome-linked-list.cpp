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
    bool isPalindrome(ListNode* head) {
        // stack<int>St;
        // ListNode* curr = head;
        // while(curr != NULL){

        //     St.push(curr->val);
        //     curr = curr->next;
        // }
        // curr = head;
        // while(curr != NULL){
        //     if(curr->val != St.top()){
        //         return false;
        //     }
        //     curr = curr->next;
        //     St.pop();
        // }
        // return true;
        
        /// Second Soln
        ListNode* Slow = head;
        ListNode* faSt = head;
        while(faSt && faSt->next){
            Slow = Slow->next;
            faSt = faSt->next->next;
        }
        ListNode* curr = Slow;
        ListNode* prev = NULL;
        ListNode* faStnext = NULL;
        while(curr != NULL){    
            faStnext= curr->next;
            curr->next = prev;
            prev = curr;
            curr = faStnext;
        }
        ListNode* firSt = head;
        ListNode* Second = prev;
        while(Second != NULL){
            if(firSt->val != Second->val){
                return false;
            }
            firSt = firSt->next;
            Second = Second->next;
        }

        return true;
    }
};