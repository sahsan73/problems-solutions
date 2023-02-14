/*
This problem is an extension of "21. Merge Two Sorted Lists"

COMPLEXITY:
    - TC = O(nlogk)
    - SC = O(n)
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        
        while(lists.size()>1) {
            vector<ListNode *> tmp;
            for(int i=0; i<lists.size(); i+=2) {
                ListNode *list1 = lists[i];
                ListNode *list2 = (i+1 < lists.size()) ? lists[i+1] : nullptr;

                tmp.push_back(mergeTwoLists(list1, list2));
            }

            lists = tmp;
        }

        return lists[0];
    }
};



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: BRUTE FORCE

COMPLEXITY:
    - TC = O(kn)
    - SC = O(1)

*/
class Solution {
private:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        ListNode *dummy, *tail;
        dummy = tail = new ListNode(-1);

        while(list1 && list2) {
            if(list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        if(list1) tail->next = list1;
        else tail->next = list2;

        return dummy->next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ans = nullptr;
        for(auto list: lists) {
            ans = mergeTwoLists(ans, list);
        }
        return ans;
    }
};
