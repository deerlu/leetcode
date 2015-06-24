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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *p = head,*prev;
        while(p != NULL && p->val == val){
            p = p->next;
            delete head;
            head = p;
        }
        if(p == NULL){
            return head;
        }
        prev = p;
        p = p->next;
        while(p != NULL){
            if(p->val == val){
                prev->next = p->next;
                delete p;
                p = prev->next;
            }else{
                prev = p;
                p = p->next;
            }
        }
        return head;
    }
};

int main()
{
    Solution s;
    ListNode* head = new ListNode(1);
    ListNode* a = new ListNode(6);
    ListNode* b = new ListNode(3);
    ListNode* c = new ListNode(5);
    ListNode* d = new ListNode(5);
    ListNode* e = new ListNode(6);
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    head = s.removeElements(head,5);
    while(head != NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
    return 0;
}
