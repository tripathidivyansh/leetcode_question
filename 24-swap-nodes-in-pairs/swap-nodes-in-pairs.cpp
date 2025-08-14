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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return NULL;
        ListNode* temp = head;
        vector<int>ans;
        while(temp != NULL){

            ans.push_back(temp->val);
            temp = temp->next;
        }
        int n = ans.size();
        for(int i = 0; i<n-1; i+=2){
            swap(ans[i], ans[i+1]);
        }
        ListNode* dummy = new ListNode(ans[0]);
        
        temp = dummy;
        for(int i = 1; i<n; i++){
            temp->next = new ListNode(ans[i]);

            temp = temp->next;
        }
        return dummy;
    }
};