#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    	ListNode *head = NULL, *r;
    	ListNode *p = l1, *q = l2;
    	int added = 0;
    	r = head;
        for(; ;){
        	if(p != NULL && q != NULL){
        		if((p->val + q->val + added) > 9){
        			r = new ListNode(p->val + q->val + added - 10);
        			added = 1;
        		}else{
        			r = new ListNode(p->val + q->val + added);
        			added = 0;
        		}
        	}else if(p != NULL){
        		r = new ListNode(p->val);
        		added = 0;
        	}else if(q != NULL){
        		r = new ListNode(q->val);
        		added = 0;
        	}else{
        		break;
        	}
        	r = r->next;
        	p = p->next;
        	q = q->next;
        }
        return head;
    }
};

int main(int argc, char **argv){
	ListNode *l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);

	ListNode *l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);
	Solution s;

	ListNode *r = s.addTwoNumbers(l1, l2);
	cout<<r->val<<"->"<<r->next->val<<"->"<<r->next->next->val<<endl;
	delete l1->next->next;
	delete l1->next;
	delete l1;
	delete l2->next->next;
	delete l2->next;
	delete l2;
	delete r;
	return 0;
}