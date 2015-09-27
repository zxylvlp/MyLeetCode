#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdlib.h>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x), next(NULL) {}
	ListNode(int x, ListNode* next): val(x), next(next) {}
	void print() {
		if (next!=NULL) {
			cout << val << " -> ";
			next->print();
		} else {
			cout << val << endl;
		}

	}
	void free() {
		if (next!=NULL) {
			next -> free();
			delete next;
		} 
		
	}
};
class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			ListNode stackAnchor(0);
			ListNode* tail = &stackAnchor;

			div_t sum = {0, 0};
			while( sum.quot || l1!=NULL || l2!=NULL ) {
				if (l1!=NULL) {
					sum.quot += l1 -> val;
					l1 = l1 -> next;
				}
				if (l2!=NULL) {
					sum.quot += l2 -> val;
					l2 = l2 -> next;
				}
				sum = div(sum.quot, 10);
				tail -> next = new ListNode(sum.rem);
				tail = tail -> next;
			}
			return stackAnchor.next;
		}
};
int main(void) {
	ListNode* a1 = new ListNode(3,NULL);
	ListNode* a2 = new ListNode(4,a1);
	ListNode* a3 = new ListNode(2,a2);
	ListNode* b1 = new ListNode(4,NULL);
	ListNode* b2 = new ListNode(6,b1);
	ListNode* b3 = new ListNode(5,b2);
	Solution* solution = new Solution;
	a3->print();
	b3->print();
	
	ListNode* result = solution->addTwoNumbers(a3, b3);

	result->print();

	a3->free();
	b3->free();
	result->free();
	delete a3;
	delete b3;
	delete result;
	delete solution;
}

