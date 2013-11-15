//============================================================================
// Insertion Sort List 
// Sort a linked list using insertion sort.
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
    ListNode *insertionSortList(ListNode *head) {
        ListNode* result = NULL;
        ListNode* curNode = head;
        while (NULL != curNode) {
            ListNode* nextNode = curNode->next;
            insertionSortHelper(result, curNode);
            curNode = nextNode;
        }
        head = result;
    }

    void insertionSortHelper(ListNode*& list, ListNode* newNode) {
        if(NULL == newNode) return;
        if(NULL == list or list->val >= newNode->val) {
            newNode->next = list;
            list = newNode;
            return;
        }
        ListNode* curNode = list;
        while (NULL != curNode->next && curNode->next->val < newNode->val)
            curNode=curNode->next;
        newNode->next = curNode->next;
        curNode->next = newNode;
    }
};

int main() {
    return 0;
}
