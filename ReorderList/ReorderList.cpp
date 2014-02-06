//============================================================================
// Reorder List
//
// Given a singly linked list L: L0->L1->...->Ln-1->Ln,
// reorder it to: L0->Ln->L1->Ln-1->L2->Ln-2->...
//
// You must do this in-place without altering the nodes' values.
//
// For example,
// Given {1,2,3,4}, reorder it to {1,4,2,3}.
//
// Complexity:
// Random Access Cache, O(n) time, O(n) space
// Split, Reverse, Merge, O(n) time, O(1) space
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
    void reorderList(ListNode *head) {
        reorderList2(head);
    }

    void reorderList1(ListNode *head) {
        if (head == NULL) return;
        vector<ListNode*> vs;
        ListNode * curNode = head;
        while (curNode != NULL) {
            vs.push_back(curNode);
            curNode = curNode->next;
        }

        int i = 0, j = vs.size()-1;
        while (i < j) {
            vs[i]->next = vs[j];
            vs[j]->next = vs[i+1];
            i++, j--;
        }
        vs[i]->next = NULL;
    }

    void reorderList2(ListNode *head) {
        if (head == NULL) return;
        ListNode * slowNode = head, *fastNode = head;
        while (fastNode->next != NULL && fastNode->next->next != NULL) slowNode = slowNode->next, fastNode = fastNode->next->next;
        if (slowNode == fastNode) return;
        fastNode = reverse(slowNode->next);
        slowNode->next = NULL;
        head = merge(head, fastNode);
    }

    ListNode * reverse(ListNode * curNode) {
        ListNode * preNode = NULL;
        while (curNode != NULL) {
            ListNode * nextNode = curNode->next;
            curNode->next = preNode;
            preNode = curNode;
            curNode = nextNode;
        }
        return preNode;
    }

    ListNode * merge(ListNode * frontNode, ListNode * backNode) {
        ListNode * head = new ListNode(-1), *curNode = head;
        while (frontNode != NULL || backNode != NULL) {
            if (frontNode != NULL) curNode->next = frontNode, frontNode = frontNode->next, curNode = curNode->next;
            if (backNode != NULL) curNode->next = backNode, backNode = backNode->next, curNode = curNode->next;
        }

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
        ListNode * head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        sol.reorderList(head);

        while (head != NULL) {
            cout << head->val << endl;
            head = head->next;
        }
    }

    return 0;
}