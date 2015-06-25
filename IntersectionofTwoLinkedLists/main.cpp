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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p,*q;
        int lengthA = 0, LengthB = 0;
        if(headA == headB){
            return headA;
        }
        p = headA;
        q = headB;
        while(p != NULL && p->next != NULL){
            p = p->next;
            lengthA++;
        }
        while(q != NULL && q->next != NULL){
            q = q->next;
            LengthB++;
        }
        if(p != q){
            return NULL;
        }
        p = headA;
        q = headB;
        if(lengthA > LengthB){
            int tmp = lengthA - LengthB;
            while(tmp--){
                p = p->next;
            }
        }else if(lengthA < LengthB){
            int tmp = LengthB - lengthA;
            while(tmp--){
                q = q->next;
            }
        }
        while(p != q){
            p = p->next;
            q = q->next;
        }
        return p;
    }
};

int main()
{
    Solution s;
    ListNode *headA = new ListNode(1);
    ListNode *a = new ListNode(2);
    ListNode *b = new ListNode(8);

    ListNode *headB = new ListNode(4);
    ListNode *c = new ListNode(5);
    ListNode *d = new ListNode(6);

    headA->next = a;
    a->next = b;
    b->next = d;
    headB->next = a;
    c->next = b;
    //d->next = b;
    headA = s.getIntersectionNode(headA,headA);
    if(headA != NULL){
        cout<<headA->val<<endl;
    }
    return 0;
}
