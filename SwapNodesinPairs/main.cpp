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
    ListNode* swapPairs(ListNode* head) {
        ListNode * start = new ListNode(-1);
        ListNode *p = start,*tmp;
        while(head != NULL){
            if(head->next != NULL){
                p->next = head->next;
                p = p->next;
                tmp = head->next->next;
                p->next = head;
                p = head;
                head = tmp;
            }else{
                p->next = head;
                p = p->next;
                break;
            }
        }
        p->next = NULL;
        p = start->next;
        delete start;
        return p;
    }
};

int main(){
	Solution s;
	ListNode * head = new ListNode(1);
	//ListNode * a = new ListNode(2);
	//ListNode * b = new ListNode(3);
	//ListNode * c = new ListNode(4);
	//head->next = a;
	//a->next = b;
	//b->next = c;
	head = s.swapPairs(head);
	while(head != NULL){
		cout<<head->val<<endl;
		head = head->next;
	}
	return 0;
}