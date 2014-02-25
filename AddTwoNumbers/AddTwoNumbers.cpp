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

ListNode * pushDummy(ListNode * head) {
    ListNode * newNode = new ListNode(-1);
    newNode->next = head;
    return newNode;
}

ListNode * popDummy(ListNode * head) {
    ListNode * delNode = head;
    head = head->next;
    delete delNode;
    return head;
}

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode * l3 = pushDummy(NULL), *cur = l3;
        int sum = 0;
        while (l1 != NULL || l2 != NULL) {
            if (l1 != NULL) sum += l1->val, l1 = l1->next;
            if (l2 != NULL) sum += l2->val, l2 = l2->next;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            sum /= 10;
        }
        if (sum > 0) cur->next = new ListNode(sum);
        return popDummy(l3);
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
