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
    ListNode *detectCycle(ListNode *head) {
        if(!head) return head;
        
        // step-I: detect the cycle
        ListNode *slow, *fast;
        slow = fast = head;
        do {
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
        } while(slow && fast && slow!=fast);
        if(!fast) return nullptr;   // there is NO cycle

        // step-II: find out the node where the cycle begins
        ListNode *node = head;
        while(node != slow) {
            node = node->next;
            slow = slow->next;
        }
        return node;
    }
};
