//============================================================================
// Linked List Cycle II
// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
//
// Follow up:
// Can you solve it without using extra space?
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
    ListNode *detectCycle(ListNode *head) {
        ListNode * runner1 = head;
        ListNode * runner2 = head;
        while (runner2 != NULL){
            runner1 = runner1 -> next;
            runner2 = runner2 -> next;
            if (runner2 == NULL || (runner2 = runner2 -> next) == NULL) 
                break;
            else if (runner1 == runner2)
            // find the result node
            {
                runner1 = head;
                while (runner1 != runner2)
                    runner1 = runner1 -> next, runner2 = runner2 -> next;
                return runner1;
            }
        }
        return NULL;
    }
};

int main() {
    return 0;
}
