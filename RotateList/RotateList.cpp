//============================================================================
// Rotate List
// Given a list, rotate the list to the right by k places, where k is
// non-negative.
//
// For example:
// Given 1->2->3->4->5->NULL and k = 2,
// return 4->5->1->2->3->NULL.
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
    ListNode *rotateRight(ListNode *head, int k) {
       if (head == NULL) return head;
       ListNode * fastNode = head;
       int l = 0;
       while (fastNode != NULL) fastNode = fastNode->next, l++;
       k %= l;
       if (k == 0) return head;
       fastNode = head;
       while (k > 0) fastNode = fastNode->next, k--;
       ListNode * slowNode = head;
       while (fastNode->next != NULL) fastNode = fastNode->next, slowNode = slowNode->next;
       fastNode->next = head;
       head = slowNode->next;
       slowNode->next = NULL;
       return head;
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
        head = sol.rotateRight(head, 6);
        while (head != NULL) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

    return 0;
}
