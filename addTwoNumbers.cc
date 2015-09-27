#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
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
			int carry = 0;
			int digitSum = 0;
			ListNode* result = NULL;
			ListNode* tail = NULL;
			ListNode* beforeTail = NULL;
			while(l1!=NULL || l2!=NULL ||carry!=0) {
				cout << 1 << endl;
				digitSum = l1!=NULL ? l1 -> val : 0;
				digitSum += l2!=NULL ? l2 -> val : 0;
				digitSum += carry;
				carry = digitSum / 10;
				digitSum = digitSum % 10;
				tail = new ListNode(digitSum, NULL);
				if (beforeTail!=NULL) {
					beforeTail->next = tail;	
					beforeTail = tail;
				} else {
					beforeTail = tail;
				}
				result = result==NULL ? tail : result;
				l1 = l1!=NULL ? l1 -> next : l1;
				l2 = l2!=NULL ? l2 -> next : l2;
			}
			return result;
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
