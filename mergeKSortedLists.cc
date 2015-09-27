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
		ListNode* mergeKLists(vector<ListNode*>& lists) {
			int size = lists.size();
			if (size==0) return NULL;
			doMerge(lists, 0, size-1);
			return lists[0];

		}	
	private:
		void doMerge(vector<ListNode*>& lists, int begin, int end) {
			if (end - begin > 0) {

				int cter = (begin+end-1)/2;
				doMerge(lists, begin, cter);
				cter++;
				doMerge(lists, cter, end);
				lists[begin] = mergeTwoLists(lists[begin], lists[cter]);
			}
		}

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
	ListNode* a3 = new ListNode(9);
	ListNode* a2 = new ListNode(5,a3);
	ListNode* a1 = new ListNode(1,a2);

	ListNode* b3 = new ListNode(10);
	ListNode* b2 = new ListNode(6,b3);
	ListNode* b1 = new ListNode(2,b2);

	ListNode* c3 = new ListNode(11);
	ListNode* c2 = new ListNode(7,c3);
	ListNode* c1 = new ListNode(3,c2);

	ListNode* d3 = new ListNode(12);
	ListNode* d2 = new ListNode(8,d3);
	ListNode* d1 = new ListNode(4,d2);
	
	cout << "source:" << endl;
	a1->print();
	b1->print();
	c1->print();
	d1->print();

	vector<ListNode*> lists{a1, b1, c1, d1};
	Solution sl;
	ListNode* res = sl.mergeKLists(lists);
	cout << "result:" << endl;
	res->print();
	res->free();
	delete res;




}
