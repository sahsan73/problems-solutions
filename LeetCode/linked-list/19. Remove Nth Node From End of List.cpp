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

/*
With Follow Up: In single Pass

COMPLEXITY:
    - TC = O(n)
    - SC = O(1)
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *q = head;
        while(--n) q = q->next;
        
        // p is a node which needs to be deleted
        ListNode *p = head, *prev_p = nullptr;
        while(q->next) {
            q = q->next;

            prev_p = p;
            p = p->next;
        }
        if(!prev_p) head = head->next;
        else prev_p->next = p->next;

        p->next = nullptr;
        delete p;
        
        return head;
    }
};
