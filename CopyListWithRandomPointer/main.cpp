#include <iostream>
#include <map>
using namespace std;
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode * headCopy,*preCopy,*nowCopy,*now;
        map<RandomListNode*,RandomListNode*> m;
        if(head == NULL){
        	return NULL;
        }
        
        headCopy =  new RandomListNode(head->label);
        m[head] = headCopy;

        preCopy = headCopy;
        now = head->next;
        while(now != NULL){
        	nowCopy = new RandomListNode(now->label);
        	preCopy->next = nowCopy;
        	m[now] = nowCopy;
        	preCopy = nowCopy;
        	now = now->next;
        }

        now = head;
        while(now != NULL){
        	if(now->random != NULL){
        		m[now]->random = m[now->random];
        	}
        	now = now->next;
        }
        return headCopy;
    }
};

int main(){
	Solution s;
	RandomListNode * head = new RandomListNode(1);
	RandomListNode * a = new RandomListNode(2);
	RandomListNode * b = new RandomListNode(3);
	RandomListNode * c = new RandomListNode(4);
	RandomListNode * d = new RandomListNode(5);
	head->next = a;
	a->next = b;
	b->next = c;
	c->next = d;
	a->random = c;
	b->random = a;

	head = s.copyRandomList(head);
	while(head != NULL){
		cout<<head->label<<" ";
		if(head->random != NULL){
			cout<<head->random->label;
		}
		cout<<endl;
		head = head->next;
	}
	return 0;
}