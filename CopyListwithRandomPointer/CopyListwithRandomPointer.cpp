//============================================================================
// A linked list is given such that each node contains an additional random 
// pointer which could point to any node in the list or null.
//
// Return a deep copy of the list. 
// 
// Complexity:
// hash table with original and copy nodes pair O(n) time O(n) space
// original node -> copy node -> original node O(n) time O(1) space
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
    RandomListNode *copyRandomList(RandomListNode *head) {
        return copyRandomList2(head);
    }

    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return head;
        unordered_map<RandomListNode *, RandomListNode *> table;
        for (RandomListNode * oldNode = head; oldNode != NULL; oldNode = oldNode->next) {
            RandomListNode * newNode = new RandomListNode(oldNode->label);
            table[oldNode] = newNode;
        }
        for (RandomListNode * oldNode = head; oldNode != NULL; oldNode = oldNode->next) {
            table[oldNode]->next = table[oldNode->next];
            table[oldNode]->random = table[oldNode->random];
        }
        return table[head];
    }

    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        for (RandomListNode * oldNode = head; oldNode != NULL; oldNode = oldNode->next->next) {
            RandomListNode * newNode = new RandomListNode(oldNode->label);
            newNode->next = oldNode->next;
            oldNode->next = newNode;
        }

        for (RandomListNode * oldNode = head; oldNode != NULL; oldNode = oldNode->next->next) {
            oldNode->next->random = (oldNode->random == NULL) ? NULL : oldNode->random->next;
        }

        RandomListNode * oldNode = head, *newHead = head->next, *newNode = newHead;
        while (true) {
            oldNode->next = newNode->next;
            oldNode = oldNode->next;
            if (oldNode == NULL) break;
            newNode->next = oldNode->next;
            newNode = newNode->next;
        }
        return newHead;
    }
};

void print(RandomListNode * head) {
    while (head != NULL) {
        cout << head->label << ",";
        if (head->random == NULL) cout << "#";
        else cout << head->random->label;
        cout << endl;
        head = head->next;
    }
}

int main() {
    Solution sol;

    {
        vector<RandomListNode *> vs;
        for (int i = 1; i <= 5; i++) vs.push_back(new RandomListNode(i));
        for (int i = 0; i < 4; i++) vs[i]->next = vs[i+1];
        vs[0]->random = vs[2];
        vs[1]->random = vs[0];
        vs[2]->random = vs[4];
        vs[3]->random = vs[2];
        vs[4]->random = vs[1];
        RandomListNode * head = vs[0];
        print(sol.copyRandomList(head));
        print(head);
    }

    {
        RandomListNode * head = new RandomListNode(-1);
        print(sol.copyRandomList(head));
        print(head);
    }

    return 0;
}
