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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return NULL;
        vector<int> arr;
        ListNode* temp = head;

        while (temp) {
            arr.push_back(temp->val);
            temp = temp->next; 
        }

        int n = arr.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if ((i == 0 || arr[i] != arr[i-1]) && (i == n-1 || arr[i] != arr[i+1])) {
                ans.push_back(arr[i]);
            }
        }
        if (ans.empty()) return NULL;
        ListNode* newHead = new ListNode(ans[0]);
        temp = newHead;

        for (int i = 1; i < ans.size(); i++) {
            temp->next = new ListNode(ans[i]);
            temp = temp->next;
        }
        return newHead;
    }
};



