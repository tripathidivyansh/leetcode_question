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
    int pairSum(ListNode* head) {
        if(!head) return NULL;
        vector<int>ans;
        ListNode* temp = head;

        while(temp != NULL){
            ans.push_back(temp->val);
            temp = temp->next;
        }
        int n = ans.size();
        int i = 0, j = n-1;
        int maxSum = 0;
        while(i < j){
            int Sum = ans[i] + ans[j];
            maxSum = max(maxSum, Sum);
            i++;
            j--;
        }
        return maxSum;
    }
};





















