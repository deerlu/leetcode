#include <iostream>
#include <set>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	set<int> setNode;
    	ListNode * q = head,*p;//p指向当前正在处理的节点,q指向p的前一个节点
    	for(p = head; p != NULL; ){
    		if(setNode.find(p->val) != setNode.end()){
    			q->next = p->next;
    			delete p;
    			p = q->next;
    		}else{
    			setNode.insert(p->val);
    			q = p;
    			p = p->next;
    		}
    	}
        return head;
    }
};

int main(){
	Solution s;
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(1);
	ListNode *c = new ListNode(2);
	ListNode *d = new ListNode(3);
	ListNode *e = new ListNode(3);
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;

	for(ListNode * p = s.deleteDuplicates(a); p != NULL; p = p->next){
		cout<<p->val<<"->";
	}
	cout<<endl;
	return 0;
}