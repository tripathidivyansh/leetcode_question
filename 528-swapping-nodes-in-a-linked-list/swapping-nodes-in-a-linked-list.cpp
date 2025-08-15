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
    ListNode* swapNodes(ListNode* head, int k) {
        // if(!head) return NULL;
        // ListNode* temp = head;
        // vector<int>ans;

        // while(temp != NULL){
        //     ans.push_back(temp->val);
        //     temp = temp->next;
        // }
        // int n = ans.size();
        // swap(ans[k-1], ans[n-k]);
        // ListNode* dummy = new ListNode(ans[0]);
        // temp = dummy;
        // for(int i = 1; i<n; i++){
        //     temp->next = new ListNode(ans[i]);
        //     temp = temp->next;
        // }
        // return dummy;
        if(!head) return NULL;
        ListNode* p1 = NULL;
        ListNode* p2 = NULL;
        ListNode* temp = head;
        while(temp != NULL){
            if(p2 != NULL){
                p2 = p2->next;
            }
            k--;
            if(k == 0){
                p1 = temp;
                p2 = head;
            }
            temp = temp->next;
        }
        swap(p1->val, p2->val);
        return head;
    }
};





