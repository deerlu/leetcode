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
    	r = head = new ListNode(0);
        for(; ;){
        	if(p != NULL && q != NULL){
        		if((p->val + q->val + added) > 9){
        			r->val = p->val + q->val + added - 10;
        			added = 1;
        		}else{
        			r->val = p->val + q->val + added;
        			added = 0;
        		}
				p = p->next;
				q = q->next;
        	}else if(p != NULL){
				if((p->val + added) > 9){
					r->val = p->val + added - 10;
					added = 1;
				}else{
					r->val = p->val + added;
					added = 0;
				}
				p = p->next;
        	}else if(q != NULL){
				if((q->val + added) > 9){
					r->val = q->val + added - 10;
					added = 1;
				}else{
					r->val = q->val + added;
					added = 0;
				}
				q = q->next;
        	}else if(added == 1){
				r->val = 1;
				added = 0;
				break;
			}else{
				break;
			}
			if(p != NULL || q != NULL || added == 1)
			{
        		r->next = new ListNode(0);
				r = r->next;
			}
		}
        return head;
    }
};

int main(int argc, char **argv){
	ListNode *l1 = new ListNode(1);
	l1->next = new ListNode(8);
	l1->next->next = new ListNode(3);

	ListNode *l2 = new ListNode(9);
	l2->next = new ListNode(9);
	l2->next->next = new ListNode(4);
	Solution s;

	ListNode *r = s.addTwoNumbers(l1, l2);
	cout<<r->val<<"->"<<r->next->val<<r->next->next->val<<endl;
	return 0;
}