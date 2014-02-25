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


ListNode * pushHead(ListNode * head) {
    ListNode * newNode = new ListNode(-1);
    newNode->next = head;
    return newNode;
}

ListNode * popHead(ListNode * head) {
    ListNode * delNode = head;
    head = head->next;
    delete delNode;
    return head;
}

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        head = pushHead(head);
        ListNode * preNode = head, *curNode = head->next;
        while (curNode != NULL) {
            ListNode * nextNode = curNode->next;
            while (nextNode != NULL && curNode->val == nextNode->val) nextNode = nextNode->next;
            if (curNode->next == nextNode) preNode = curNode, curNode = nextNode;
            else {
                preNode->next = nextNode;
                while (curNode != nextNode) curNode = popHead(curNode);
            }
        }
        return popHead(head);
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
