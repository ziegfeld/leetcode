//============================================================================
// Sort List 
// Sort a linked list in O(n log n) time using constant space complexity.
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
    ListNode *sortList(ListNode *head) {
        if (NULL == head || NULL == head->next) return head;
        ListNode* front;
        ListNode* back;
        frontBackSplit(head, front, back);
        front = sortList(front);
        back = sortList(back);
        return sortedMerge1(front, back);
    }

    void frontBackSplit(ListNode* head, ListNode*& front, ListNode*& back) {
        front = head;
        back = NULL;
        if (NULL == front) return;
        ListNode* preBack;
        back = front;
        ListNode* tail = front;
        while (NULL != tail) {
            preBack = back;
            back = back->next;
            tail = (tail->next) ? (tail->next)->next : NULL;
        }
        preBack->next = NULL;
    }

    ListNode* sortedMerge1(ListNode* front, ListNode* back) {
        if (NULL == front) return back;
        if (NULL == back) return front;
        ListNode* head;
        if (front->val <= back->val) {
            head = front;
            front->next = sortedMerge1(front->next, back);
        }
        else {
            head = back;
            back->next = sortedMerge1(front, back->next);
        }
        return head;
    }

    ListNode* sortedMerge2(ListNode* front, ListNode* back) {
        if (front == NULL) return back;
        if (back == NULL) return front;
        ListNode* head = NULL;
        ListNode* ListNode = head;
        while(true) {
            if (NULL == front) {
                if (head == NULL) head = back;
                ListNode->next = back;
                break;
            }
            if (NULL == back) {
                if (head == NULL) head = front;
                ListNode->next = front;
                break;
            }
            if(front->val <= back->val) {
                if (head == NULL) ListNode = front;
                else ListNode->next = front;
                front = front->next;
            }
            else {
                if (head == NULL) ListNode = back;
                else ListNode->next = back;
                back = back->next;
            }
            if (head == NULL) head = ListNode;
            else ListNode = ListNode->next;
        }
        return head;
    }
};

int main() {
    return 0;
}
