//============================================================================
// Remove Nth Node From End of List
// Given a linked list, remove the nth node from the end of list and return
// its head.
//
// For example,
//
// Given linked list: 1->2->3->4->5, and n = 2.
//
// After removing the second node from the end, the linked list becomes
// 1->2->3->5.
// Note:
// Given n will always be valid.
// Try to do this in one pass.
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
    ListNode(int x) : val(x), next(NULL) {};
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (!head) return NULL;
        ListNode * pre = new ListNode(-1);
        pre -> next = head;
        ListNode * runner = head;
        head = pre;
        
        while (--n > 0 && runner != NULL)
            runner = runner -> next;
        if (runner == NULL && n != 0) return pre -> next;
        
        ListNode * res = head;
        while (runner != NULL)
            runner = runner -> next, pre = res, res = res -> next;
        pre -> next = res -> next;
        delete res;
        
        return head -> next;
//        return popHead(head); //anson's newer version
    }
	ListNode * popHead(ListNode * head) {
	    ListNode * delNode = head;
	    head = head->next;
	    delete delNode;
	    return head;
	}

};

int main() {
    return 0;
}
