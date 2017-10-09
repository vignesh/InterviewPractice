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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return NULL;
        }
        while (lists.size() > 1) {
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
    
    ListNode* mergeTwoLists(ListNode *a, ListNode *b) {
        if (!a) {
            return b;
        }
        else if (!b) {
            return a;
        }
        else if (a->val <= b->val) {
            a->next = mergeTwoLists(a->next, b);
            return a;
        }
        else {
            b->next = mergeTwoLists(a, b->next);
            return b;
        }
    }
};
