//============================================================================
// You are given two linked lists representing two non-negative numbers.
// The digits are stored in reverse order and each of their nodes contain a
// single digit. Add the two numbers and return it as a linked list.
//
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
//
// Complexity:
// O(m+n)
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode * head = new ListNode(-1), * curNode = head;
        int c = 0;
        while (l1 != NULL || l2 != NULL) {
            int s = c;
            if (l1 != NULL) s += l1->val, l1 = l1->next;
            if (l2 != NULL) s += l2->val, l2 = l2->next;
            curNode->next = new ListNode(s%10);
            curNode = curNode->next;
            c = s/10;
        }
        if (c != 0) curNode->next = new ListNode(c);
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
    Solution sol;

    {
        ListNode * l1 = new ListNode(2);
        l1->next = new ListNode(4);
        l1->next->next = new ListNode(3);
        ListNode * l2 = new ListNode(5);
        l2->next = new ListNode(6);
        l2->next->next = new ListNode(4);
        ListNode * res = sol.addTwoNumbers(l1, l2);
        while (res != NULL) {
            cout << res->val << " ";
            res = res->next;
        }
        cout << endl;
    }
    return 0;
}
