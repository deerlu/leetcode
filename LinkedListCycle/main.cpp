#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *oneStep = head,*twoStep = head;
      	
        while(true){
        	if(oneStep == NULL){
        		return false;
        	}
        	oneStep = oneStep->next;
        	
        	if(twoStep == NULL){
        		return false;
        	}
        	twoStep = twoStep->next;

        	if(twoStep == NULL){
        		return false;
        	}
        	twoStep = twoStep->next;

        	if(oneStep == twoStep){
        		return true;
        	}
        }
    }
};

int main(){
	Solution s;
	ListNode *head = new ListNode(1);
	ListNode *a = new ListNode(2);
	ListNode *b = new ListNode(3);
	ListNode *c = new ListNode(4);
	head->next = a;
	a->next = b;
	b->next = c;
	c->next = b;
	cout<<s.hasCycle(head)<<endl;
	return 0;
}