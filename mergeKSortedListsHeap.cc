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
void printVec(vector<ListNode*>& lists) {
	for(auto iter = lists.begin(); iter != lists.end(); iter++) {
		cout << ((*iter) -> val) << " ";

	}
	cout << endl;
}
class Solution {
	public:
		ListNode* mergeKLists(vector<ListNode*>& lists) {

			auto l_it_begin = lists.begin();
			auto l_it_end = lists.end();

			l_it_end = remove_if(l_it_begin, l_it_end, isNull);
			if (l_it_begin == l_it_end) return nullptr;

			ListNode* head = nullptr;
			ListNode* tail = nullptr;

			make_heap(l_it_begin, l_it_end, minHeapPred);
			head = tail = *l_it_begin;

			while(distance(l_it_begin, l_it_end) > 1) {
				pop_heap(l_it_begin, l_it_end, minHeapPred);
						
				--l_it_end;
				*l_it_end = (*l_it_end)->next;

				if (*l_it_end) {
					++l_it_end;
					push_heap(l_it_begin, l_it_end, minHeapPred);
				}

				tail->next = *l_it_begin;
				tail = tail->next;
			}
			return head;

		}	
	private:
		static bool isNull(const ListNode* a) {
			return a==nullptr;
		}

		static bool minHeapPred(const ListNode* a, const ListNode* b) {
			return a->val > b->val;
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
