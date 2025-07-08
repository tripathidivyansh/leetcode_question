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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>arr;
        ListNode* temp = head;
        while(temp != NULL){

            arr.push_back(temp->val);
            temp = temp->next;
        }
        int n = arr.size();
        vector<int>result(n, 0);
        stack<int>St;
        for(int i = n-1; i>=0; i--){
            while(!St.empty() && St.top() <= arr[i]){
                St.pop();
            }
            if(!St.empty()){
                result[i] = St.top();
            }
            St.push(arr[i]);
        }
        return result;
    }
};