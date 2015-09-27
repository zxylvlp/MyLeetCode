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
		ListNode* reverseList(ListNode* head) {
			if (head==NULL)
				return NULL;
			ListNode* p = head->next;
			head->next = NULL;
			while(p) {
				ListNode* ptmp = p->next;
				p->next = head;
				head = p;
				p = ptmp;
			}
			return head;
		}

};
int main() {
	ListNode* a6 = new ListNode(6, NULL);
	ListNode* a5 = new ListNode(5, a6);
	ListNode* a4 = new ListNode(4, a5);
	ListNode* a3 = new ListNode(3, a4);
	ListNode* a2 = new ListNode(2, a3);
	ListNode* a1 = new ListNode(1, a2);
	cout<<"source:"<<endl;
	a1->print();
	Solution sl;
	ListNode* result = sl.reverseList(a1);
	cout<<"result:"<<endl;
	result->print();
	result->free();
	delete result;

}

