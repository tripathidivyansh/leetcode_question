/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // ListNode* nextNode = node-> next;
        // node-> val = node-> next-> val;
        // node-> next = node -> next-> next;
        // delete nextNode;
        // ListNode* nextNode = node-> next;
        // node->val = node-> next-> val;
        // node-> next = node->next -> next;

        // delete nextNode;
        if(node == NULL || node->next == NULL){
            return;
        }
        ListNode* temp = node;
        while(temp != NULL && temp->next != NULL){
            temp->val = temp->next->val;

            if(temp->next->next == NULL){
                ListNode* todelete = temp->next;
                temp->next = NULL;
                delete todelete;
                break;
            }
            temp= temp->next;
        }
    }
};