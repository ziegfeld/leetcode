//============================================================================
// Reverse a linked list from position m to n. Do it in-place and in one-pass.
//
// For example:
// Given 1->2->3->4->5->NULL, m = 2 and n = 4,
//
// return 1->4->3->2->5->NULL.
//
// Note:
// Given m, n satisfy the following condition:
// 1 ≤ m ≤ n ≤ length of list.
//============================================================================

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode * newHead = new ListNode(-1);
        newHead->next = head;
        ListNode * preNode = NULL, * curNode = newHead;
        for (int i = 0; i < m; i++) preNode = curNode, curNode = curNode->next;
        ListNode * preTail = preNode;
        preNode = NULL;
        for (int i = 0; i <= n-m; i++) {
            ListNode * nextNode = curNode->next;
            curNode->next = preNode;
            preNode = curNode;
            curNode = nextNode;
        }
        preTail->next->next = curNode;
        preTail->next = preNode;
		return deleteNode(newHead);
    }

	ListNode * deleteNode(ListNode * curNode) {
		ListNode * toDel = curNode;
		curNode = curNode->next;
		delete toDel;
		return curNode;
	}
};

int main() {
    Solution sol;

    {
        ListNode * head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        head->next->next->next->next = new ListNode(5);
        head = sol.reverseBetween(head, 2, 4);
        while (head != NULL) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

    return 0;
}
