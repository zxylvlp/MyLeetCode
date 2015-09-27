#include <iostream>
#include <limits.h>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) {}
	ListNode(int x, ListNode* nextt): val(x), next(nextt) {}
	void print() {
		if(next!=NULL) {
			cout << val << " -> ";
			next->print();
		} else {
			cout << val << endl;
		}
	}
	void free() {
		if(next!=NULL) {
			next->free();
			delete next;
		}
		
	}
};
class Solution {
	public:
		ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
			ListNode dummy(INT_MIN);
			ListNode* tail = &dummy;
			while(l1&&l2) {
				if (l1->val < l2->val) {
						tail->next = l1;
						tail = l1;
						l1 = l1->next;
				} else {
					tail->next = l2;
					tail = l2;
					l2 = l2->next;
				}
			}
			tail->next = l1? l1:l2;
			return dummy.next;
		}

};
int main() {
	ListNode* a3 = new ListNode(5, NULL);
	ListNode* a2 = new ListNode(3, a3);
	ListNode* a1 = new ListNode(1, a2);

	ListNode* b3 = new ListNode(6, NULL);
	ListNode* b2 = new ListNode(4, b3);
	ListNode* b1 = new ListNode(2, b2);
	Solution sl;
	ListNode* result = sl.mergeTwoLists(a1,b1);
	result->print();
	result->free();
	delete result;

}
