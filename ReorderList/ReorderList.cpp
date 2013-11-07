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
        bool done = false;
        reorderListHelper(head, head, done);
    }

    void reorderListHelper(ListNode *& front, ListNode * back, bool & done) {
        if (back == NULL) return;
        reorderListHelper(front, back->next, done);
        if (done) return;

        if (front == back || front->next == back) {
            back->next = NULL;
            done = true;
            return;
        }

        ListNode * next = front->next;
        front->next = back;
        back->next = next;
        front = next;
    }
};

int main() {
    return 0;
}