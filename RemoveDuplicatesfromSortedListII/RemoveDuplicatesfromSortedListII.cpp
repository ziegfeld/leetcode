//============================================================================
// Remove Duplicates from Sorted List II
// Given a sorted linked list, delete all nodes that have duplicate numbers,
// leaving only distinct numbers from the original list.
//
// For example,
// Given 1->2->3->3->4->4->5, return 1->2->5.
// Given 1->1->1->2->3, return 2->3.
//
// Complexity:
// O(n) time
//============================================================================

#include <iostream>
using namespace std;

/*
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode * newHead = new ListNode(-1);
        newHead->next = head;
        ListNode * curNode = newHead;
        while (curNode->next != NULL) {
            ListNode * nextNode = curNode->next;
            while (nextNode->next != NULL && nextNode->val == nextNode->next->val) nextNode = nextNode->next;
            if (nextNode == curNode->next) {
                curNode = nextNode;
                continue;
            }
            nextNode = nextNode->next;
            while (curNode->next != nextNode) curNode->next = deleteNode(curNode->next);
        }

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
        head->next->next->next = new ListNode(3);
        head->next->next->next->next = new ListNode(4);
        head->next->next->next->next->next = new ListNode(4);
        head->next->next->next->next->next->next = new ListNode(5);
        head = sol.deleteDuplicates(head);
        while (head != NULL) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

    {
        ListNode * head = new ListNode(1);
        head->next = new ListNode(1);
        head->next->next = new ListNode(1);
        head->next->next->next = new ListNode(2);
        head->next->next->next->next = new ListNode(3);
        head = sol.deleteDuplicates(head);
        while (head != NULL) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

    return 0;
}
