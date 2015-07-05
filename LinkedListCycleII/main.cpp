#include <iostream>
#include <set>
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
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> setListNodeStar;
        ListNode *p;
        p = head;
        while(p){
        	if(setListNodeStar.find(p) != setListNodeStar.end()){
        		return p;
        	}else{
        		setListNodeStar.insert(p);
        	}
        	p = p->next;
        }
        return NULL;
    }
};

int main(){
	Solution s;
	ListNode *head = new ListNode(1);
	ListNode *a = new ListNode(2);
	//ListNode *b = new ListNode(3);
	//ListNode *c = new ListNode(4);
	head->next = a;
	a->next = head;
	//b->next = c;
	//c->next = a;
	if((head = s.detectCycle(head)) && head){
		cout<<head->val<<endl;
	}
	return 0;
}