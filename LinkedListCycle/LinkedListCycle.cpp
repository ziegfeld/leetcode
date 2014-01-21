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
        ListNode * fastNode = head, * slowNode = head;
        while (fastNode != NULL && fastNode->next != NULL) {
            fastNode = fastNode->next->next;
            slowNode = slowNode->next;
            if (fastNode == slowNode) return true;
        }
        return false;
    }
};

int main() {
    return 0;
}
