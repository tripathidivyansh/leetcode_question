class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* curr = head;
        stack<ListNode*> s;

        while (curr != NULL) {
            while (!s.empty() && s.top()->val < curr->val) {
                s.pop();
            }
            s.push(curr);
            curr = curr->next;
        }
        ListNode* nxt = NULL;
        while (!s.empty()) {
            curr = s.top();

            s.pop();
            curr->next = nxt;
            nxt = curr;
        }
        return nxt;
    }
};
