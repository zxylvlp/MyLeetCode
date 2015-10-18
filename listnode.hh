/**
 * Definition for singly-linked list.
 */
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void printList(ListNode *list) {
    if (list!=nullptr) {
        cout << list->val << " ";
        printList(list->next);
    } else {
        cout << endl;
    }
}

