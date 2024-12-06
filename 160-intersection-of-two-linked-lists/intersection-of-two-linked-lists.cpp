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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL){
            return NULL;
        }
        ListNode* temp = headB;
        while(headA != NULL){
            temp = headB;
            while(temp != NULL){
                if(headA == temp){
                    return headA;
                }
                temp = temp->next;
            }
            headA = headA->next;
        }
        return NULL;
    }
};




















































/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         if(headA == NULL || headB == NULL){
//             return NULL;
//         }
//         ListNode* temp = headB;
//         while(headA != NULL){
//             temp = headB;
//             while(temp != NULL){
//                 if(headA == temp){
//                     return headA;
//                 }
//                 temp = temp->next;
//             }
//             headA = headA->next;
//         }
//         return NULL;
//     }
// };