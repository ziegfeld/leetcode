//============================================================================
// Swap Nodes in Pairs
// Given a linked list, swap every two adjacent nodes and return its head.
//
// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.
//
// Your algorithm should use only constant space. You may not modify the
// values in the list, only nodes itself can be changed.
//
// Complexity:
// O(n)
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
    ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode * pre = new ListNode(-1);
        pre->next = head;
        
        ListNode * p = head, * q = head->next;
        head = pre;
        while (p && q){
            pre->next = q;
            p->next = q->next;
            q->next = p;
         
            pre = p;
            p = p->next;
            q = (p) ? (p->next) : NULL;
        }
        return head->next;
    }//better than anson627
};

int main() {
    Solution sol;
    ListNode * head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head = sol.swapPairs(head);
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}
