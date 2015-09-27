#include <iostream>
#include <vector>
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
		ListNode* swapPairs(ListNode* head) {
			ListNode dummy(0);
			dummy.next=head;
			ListNode* beforeTail = &dummy;
			ListNode* tail = head;
			while (tail && tail->next) {
				beforeTail->next = swapNode(tail, tail->next);
				beforeTail = tail;
				tail = tail->next;

			}
			return dummy.next;

		}	
	private:
		ListNode* swapNode(ListNode* l1, ListNode* l2) {
			l1->next = l2->next;
			l2->next = l1;
			return l2;
		}
};

int main() {
	ListNode* a5 = new ListNode(5);
	ListNode* a4 = new ListNode(4,a5);
	ListNode* a3 = new ListNode(3,a4);
	ListNode* a2 = new ListNode(2,a3);
	ListNode* a1 = new ListNode(1,a2);

	
	cout << "source:" << endl;
	a1->print();

	Solution sl;
	ListNode* res = sl.swapPairs(a1);
	cout << "result:" << endl;
	res->print();
	res->free();

	delete res;




}

