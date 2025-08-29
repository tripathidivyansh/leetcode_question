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
    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode* temp = head;
        vector<int> ans;

        while(temp){
            ans.push_back(temp->val);
            temp = temp->next;
        }
        vector<int> reordered;
        int l = 0, r = ans.size()-1;
        while(l <= r){
            if(l == r) {
                reordered.push_back(ans[l]); 
            } else {
                reordered.push_back(ans[l]);
                reordered.push_back(ans[r]);
            }
            l++;
            r--;
        }
        temp = head;
        for(int i = 0; i < reordered.size(); i++){
            temp->val = reordered[i]; 
            temp = temp->next;
        }
    }
};









