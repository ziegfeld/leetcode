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
        ListNode * head = new ListNode(-1), * curNode = head;
        while(l1 != NULL || l2 != NULL) {
            if (l2 == NULL || (l1 != NULL && l1->val < l2->val)) curNode->next = l1, l1 = l1->next;
            else curNode->next = l2, l2 = l2->next;
            curNode = curNode->next;
        }
        return deleteNode(head);
    }

	ListNode * deleteNode(ListNode * curNode) {
		ListNode * toDel = curNode;
		curNode = curNode->next;
		delete toDel;
		return curNode;
	}
};

int main() {
    return 0;
}
