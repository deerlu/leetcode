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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pre,*now,*post;
        if(!head){
            return NULL;
        }
        ListNode * addedHead = new ListNode(head->val+1);
        addedHead->next = head;
        pre = addedHead;
        now = head;
        post = head->next;
        while(post){
            if(now->val == post->val){
                int val = now->val;
                while(now && now->val == val){
                    pre->next = now->next;
                    delete now;
                    now = pre->next;
                }
                if(now){
                    post = now->next;
                }else{
                    post = NULL;
                }
                
            }else{
                pre = now;
                now = now->next;
                post = post->next;
            }
        }
        ListNode * tmp = addedHead->next;
        delete addedHead;
        return tmp;
    }
};

int main(){
    Solution s;
    ListNode * head = new ListNode(2);
    ListNode * a = new ListNode(2);
    ListNode * b = new ListNode(3);
    ListNode * c = new ListNode(3);
    ListNode * d = new ListNode(4);
    ListNode * e = new ListNode(4);
    ListNode * f = new ListNode(5);
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    head = s.deleteDuplicates(head);
    while(head != NULL){
        cout<<head->val<<endl;
        head = head->next;
    }
    return 0;
}