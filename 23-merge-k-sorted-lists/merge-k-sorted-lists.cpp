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
    ListNode* mergetwoSorted(ListNode* l1 , ListNode* l2){
        if(!l1 ) return l2;
        if(!l2) return l1;
        if(l1->val <= l2->val){
            l1->next = mergetwoSorted(l1->next, l2);
            return l1;
        }else{
            l2->next = mergetwoSorted(l1, l2->next);
            return l2;
        }
        return NULL;
    }
    ListNode* partion(int Start, int end, vector<ListNode*>& lists){
        if(Start > end){
            return NULL;
        }
        if(Start == end){
            return lists[Start];
        }
        int mid = Start + (end-Start)/2;
        ListNode* l1 = partion(Start, mid, lists);
        ListNode* l2 = partion(mid+1, end, lists);
        return mergetwoSorted(l1, l2);

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k == 0) return NULL;
        return partion(0, k-1, lists);
    }
};











