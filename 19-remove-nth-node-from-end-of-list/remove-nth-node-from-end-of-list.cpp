/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}

 */
class Solution {
    
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<int>ans;
        ListNode* temp = head;
        while(temp){
            ans.push_back(temp->val);
            temp = temp->next;
        }
        int size = ans.size();
        ans.erase(ans.begin() + (size - n));

        ListNode* newHead = nullptr;
        ListNode* tail = nullptr;
        for(int val : ans) {
            ListNode* node = new ListNode(val);
            if(!newHead) {
                newHead = node;
                tail = node;
            } else {
                tail->next = node;
                tail = node;

            }
        }
        
        return newHead;
    }
};















