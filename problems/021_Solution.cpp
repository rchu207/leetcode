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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(0);
        ListNode* now = l3;
        
        while (l1 != NULL || l2 != NULL) {
            if (l1 == NULL) {
                now->next = new ListNode(l2->val);
                l2 = l2->next;
            } else if (l2 == NULL || l1->val <= l2->val) {
                now->next = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                now->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            now = now->next;                
        }

        return l3->next;
    }
};
