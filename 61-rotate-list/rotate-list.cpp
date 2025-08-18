class Solution {
public:
    ListNode* findKthNode(ListNode* head, int k) {
        int count = 1;
        while (head != nullptr) {
            if (count == k) return head;
            head = head->next;
            count++;
        }
        return nullptr;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;

        ListNode* tail = head;
        int len = 1;
        while (tail->next) {
            tail = tail->next;
            len++;
        }

        k %= len;
        if (k == 0) return head;

        tail->next = head;

        ListNode* newTail = findKthNode(head, len - k);
        ListNode* newHead = newTail->next;

        newTail->next = nullptr;

        return newHead;
    }
};








