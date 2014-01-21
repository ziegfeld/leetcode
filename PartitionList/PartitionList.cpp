//============================================================================
// Partition List
// Given a linked list and a value x, partition it such that all nodes less
// than x come before nodes greater than or equal to x.
//
// You should preserve the original relative order of the nodes in each of the
// two partitions.
//
// For example,
// Given 1->4->3->2->5->2 and x = 3,
// return 1->2->2->4->3->5.
//
// Complexity:
// O(n) time
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
	ListNode *partition(ListNode *head, int x) {
		ListNode* frontHead = new ListNode(-1), *frontNode = frontHead;
		ListNode* backHead = new ListNode(-1), *backNode = backHead;
		while (head != NULL) {
			if (head->val < x) frontNode->next = head, frontNode = frontNode->next;
			else backNode->next = head, backNode = backNode->next;
			head = head->next;
		}
		backNode->next = NULL;
		frontNode->next = deleteNode(backHead);
		return deleteNode(frontHead);
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
		head->next = new ListNode(4);
		head->next->next = new ListNode(3);
		head->next->next->next = new ListNode(2);
		head->next->next->next->next = new ListNode(5);
		head->next->next->next->next->next = new ListNode(2);
		head = sol.partition(head, 3);
		while (head != NULL) {
			cout << head->val << " ";
			head = head->next;
		}
		cout << endl;
	}
	return 0;
}