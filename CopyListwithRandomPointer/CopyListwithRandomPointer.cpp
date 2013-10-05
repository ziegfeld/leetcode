//============================================================================
// A linked list is given such that each node contains an additional random 
// pointer which could point to any node in the list or null.
//
// Return a deep copy of the list. 
//
//============================================================================

#include <iostream>

using namespace std;
/**
 * Definition for singly-linked list with a random pointer.
 */
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode * copyRandomList(RandomListNode* head) {
        if (head == NULL) return NULL;
        // clone nodes
        RandomListNode * curNode = head;
        while (curNode != NULL) {
            RandomListNode * newNode = new RandomListNode(curNode->label);
            newNode->random = NULL;
            newNode->next = curNode->next;
            curNode->next = newNode;
            curNode = newNode->next;
        }

        // clone randoms
        curNode = head;
        while (curNode != NULL) {
            if (curNode->random != NULL) curNode->next->random = curNode->random->next;
            else curNode->next->random = NULL;
            curNode = curNode->next->next;
        };

        RandomListNode* clonedHead = head->next;
        curNode = head;
        RandomListNode* clonedNode = head->next;

        while(curNode != NULL) {
            curNode->next = curNode->next->next;
            curNode = curNode->next;
            if (clonedNode->next != NULL) {
                clonedNode->next = clonedNode->next->next;
                clonedNode = clonedNode->next;
            }
        }
        return clonedHead;
    };
};

int main() {
    return 0;
}
