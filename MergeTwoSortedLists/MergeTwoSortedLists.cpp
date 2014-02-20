//============================================================================
// Merge two sorted linked lists and return it as a new list. The new list
// should be made by splicing together the nodes of the first two lists.
//
// Complexity
// O(n+m)
//============================================================================

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
};


class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1==NULL) return l2;
        
        ListNode * res = new ListNode (0);
        res->next = l1;
        l1 = res;
        
        while (l1->next != NULL) {
            if (l2==NULL) return res->next;
            ListNode *cur = l1->next;
            if (cur->val > l2->val) {
                l1->next = l2;
                l2 = l2->next;
                l1->next->next = cur;
            } else
                l1 = l1->next;
        }
        l1->next = l2;
        
        //3 lines to delete the dummy head.
        ListNode * toDel = res;
        res = res->next;
        delete toDel;
        
        return res;
        
        
    }
};

int main() {
    return 0;
}
