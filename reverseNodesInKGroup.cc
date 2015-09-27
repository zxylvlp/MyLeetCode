#include <iostream>
#include <stdlib.h>
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
		ListNode* reverseKGroup(ListNode* head, int k) {
			
			if (head==NULL||k==1) return head;
			ListNode dummy(-1);
			dummy.next = head;
			int num = 0;
			ListNode *cur = head, *pre, *nxt = head;
			while(cur) {
				num++;
				cur = cur->next;
			}
			cur = &dummy;
			while(num>=k) {
				pre = cur;
				cur = nxt;
				nxt = cur->next;
				for(int i=1; i<k; i++) {
					cur->next = nxt->next;
					nxt->next = pre->next;
					pre->next = nxt;
					nxt = cur->next;
				}
				num-=k;
			}
			return dummy.next;
		}

};
int main() {
	ListNode* a5 = new ListNode(5, NULL);
	ListNode* a4 = new ListNode(4, a5);
	ListNode* a3 = new ListNode(3, a4);
	ListNode* a2 = new ListNode(2, a3);
	ListNode* a1 = new ListNode(1, a2);
	cout<<"source:"<<endl;
	a1->print();
	Solution sl;
	ListNode* result = sl.reverseKGroup(a1, 3);
	cout<<"result:"<<endl;
	result->print();
	result->free();
	delete result;
}


