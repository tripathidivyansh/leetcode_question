class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        int preSum = 0;
        unordered_map<int, ListNode*> mp;
        
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        mp[0] = dummyNode;
        
        while (head != nullptr) {
            preSum += head->val;
            if (mp.find(preSum) != mp.end()) {
                ListNode* start = mp[preSum];
                ListNode* temp = start->next;
                int sum = preSum;
                
                
                while (temp != head) {
                    sum += temp->val;
                    mp.erase(sum);
                    temp = temp->next;
                }
                start->next = head->next; 
            } else {
                mp[preSum] = head;
            }
            head = head->next;
        }
        
        return dummyNode->next;
    }
};
