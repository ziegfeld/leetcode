//============================================================================
// Linked List Cycle 
// Given a linked list, determine if it has a cycle in it.
//
// Follow up:
// Can you solve it without using extra space?
//
// Complexity
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
    bool hasCycle(ListNode *head) {
        ListNode * runner1 = head;
        ListNode * runner2 = head;
        while (runner2 != NULL){
            runner1 = runner1 -> next;
            runner2 = runner2 -> next;
            if (runner2 == NULL || (runner2 = runner2 -> next) == NULL) 
                return false;
            else if (runner1 == runner2)
                return true;
        }
        return false;
    }
};

int main() {
    return 0;
}
