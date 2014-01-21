//============================================================================
// Reverse Nodes in k-Group
// Given a linked list, reverse the nodes of a linked list k at a time and
// return its modified list.
//
// If the number of nodes is not a multiple of k then left-out nodes in the
// end should remain as it is.
//
// You may not alter the values in the nodes, only nodes itself may be
// changed.
//
// Only constant memory is allowed.
//
// For example,
// Given this linked list: 1->2->3->4->5
//
// For k = 2, you should return: 2->1->4->3->5
//
// For k = 3, you should return: 3->2->1->4->5
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k < 2) return head;
        int l = 0;
        ListNode *curNode = head;
        while (curNode != NULL) curNode = curNode->next, l++;
        return reverseKGroup2(head, k, l);
    }

    ListNode *reverseKGroup1(ListNode * curNode, int k, int l) {
        if (l < k) return curNode;
        ListNode * curTail = curNode, * preNode = NULL;
        for (int i = 0; i < k; i++) {
            ListNode * nextNode = curNode->next;
            curNode->next = preNode;
            preNode = curNode;
            curNode = nextNode;
        }
        curTail->next = reverseKGroup1(curNode, k, l-k);
        return preNode;
    }

    ListNode *reverseKGroup2(ListNode *head, int k, int l) {
        if (l < k) return head;
        ListNode * preTail = NULL, * curTail = NULL, * curNode = head;
        for (int i = 0; i < l/k; i++) {
            ListNode * preNode = NULL;
            curTail = curNode;
            for (int j = 0; j < k; j++) {
                ListNode * nextNode = curNode->next;
                curNode->next = preNode;
                preNode = curNode;
                curNode = nextNode;
            }
            if (preTail == NULL) head = preNode;
            else preTail->next = preNode;
            preTail = curTail;
        }
        curTail->next = curNode;
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
        head = sol.reverseKGroup(head, 2);
        while (head != NULL) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

    {
        ListNode * head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        head->next->next->next->next = new ListNode(5);
        head = sol.reverseKGroup(head, 3);
        while (head != NULL) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
