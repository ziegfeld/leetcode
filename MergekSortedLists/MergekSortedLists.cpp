//============================================================================
// Merge k sorted linked lists and return it as one sorted list.
// Analyze and describe its complexity.
//
// Complexity:
// O(nlog(k)) time
//============================================================================

#include <iostream>
#include <queue>
#include <vector>
using namespace std;


/**
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {};
};

struct cmp {
    bool operator() (ListNode * a, ListNode * b) { return a->val > b->val; };
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (auto curNode : lists) if (curNode != NULL) pq.push(curNode);
        ListNode * head = new ListNode(-1), * curNode = head;
        while (!pq.empty()) {
            ListNode * nextNode = pq.top();
            pq.pop();
            if (nextNode->next != NULL) pq.push(nextNode->next);
            curNode->next = nextNode;
            curNode = curNode->next;
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
    return 0;
}
