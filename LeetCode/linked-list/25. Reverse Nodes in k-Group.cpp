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
private:
    int lengthLL(ListNode *head) {
        int cnt = 0;
        while(head) {
            ++cnt;
            head = head->next;
        }
        return cnt;
    }

    void reverseLL(ListNode *head) {
        ListNode *prevNewHead=nullptr, *newHead=nullptr;
        while(head) {
            prevNewHead = newHead;
            newHead = head;
            head = head->next;

            newHead->next = prevNewHead;
        }
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = lengthLL(head);
        int gp = len / k;

        ListNode *newHead=nullptr, *tail = nullptr;
        while(gp-- && head) {
            ListNode *a = head, *b = nullptr;
            for(int i=0; i<k; ++i) {
                b = head;
                head = head->next;
            }
            b->next = nullptr;

            reverseLL(a);

            if(!newHead) newHead = b;
            else tail->next = b;
            tail = a;
        }

        tail->next = head;
        return newHead;
    }
};



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// RECURSIVE IMPLEMENTATION
class Solution {
private:
    void reverseLL(ListNode *head) {
        ListNode *prevNewHead=nullptr, *newHead=nullptr;
        while(head) {
            prevNewHead = newHead;
            newHead = head;
            head = head->next;

            newHead->next = prevNewHead;
        }
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *a=head, *b=nullptr;
        int t = k;
        while(head && t--) {
            b = head;
            head = head->next;
        }
        if(t>0) return a;

        b->next = nullptr;
        reverseLL(a);

        a->next = reverseKGroup(head, k);
        return b;
    }
};
