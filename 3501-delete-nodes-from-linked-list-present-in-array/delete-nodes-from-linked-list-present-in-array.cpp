class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(0);

        ListNode* tail = dummy;
        ListNode* curr = head;
        while (curr) {
            ListNode* nxt = curr->next;

            if (!s.count(curr->val)) {
                tail->next = curr;
                tail = curr;
                tail->next = nullptr;
            }
            curr = nxt;
        }
        return dummy->next;
    }
};
