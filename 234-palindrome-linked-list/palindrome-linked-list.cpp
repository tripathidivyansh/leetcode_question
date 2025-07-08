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
        stack<int>s;
        queue<int>q;
        if(head == NULL){
            
            return true;
        }
        while(head != NULL){

            s.push(head->val);
            q.push(head->val);
            head = head->next;
        }
        while(!s.empty() && !q.empty()){
            if(s.top() != q.front()){
                return false;
            }
            s.pop();
            q.pop();
        }
        return true;
    }
};