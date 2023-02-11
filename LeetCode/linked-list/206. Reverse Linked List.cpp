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
    ListNode* reverseList(ListNode* head) {
        ListNode *prevNewHead=nullptr, *newHead=nullptr;
        while(head) {
            prevNewHead = newHead;
            newHead = head;
            head = head->next;

            newHead->next = prevNewHead;
        }
        return newHead;
    }
};
