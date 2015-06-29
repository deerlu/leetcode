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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * p1,*p2,*prev,*head,*tmp,*prev2;
        p1 = l1;
        p2 = l2;
        if(l2 == NULL){
            return l1;
        }else if(l1 == NULL){
            return l2;
        }else{
            head = p1;
            if(p1->val > p2->val){
                head = p2;
                p1 = l2;
                p2 = l1;
            }
            prev = p1;
            while(p2 != NULL){
                while(p1 != NULL && p1->val <= p2->val){
                    prev = p1;
                    p1 = p1->next;
                }
                if(p1 == NULL){
                    prev->next = p2;
                    return head;
                }else{
                    prev->next = p2;
                    prev2 = p2;
                    while(p2 != NULL && p1->val >= p2->val){
                        prev2 = p2;
                        p2 = p2->next;
                    }
                    tmp = prev2->next;
                    prev2->next = p1;
                    p2 = tmp;
                }
            }
            return head;
        }

    }
};

int main()
{
    Solution s;
    ListNode * l1 = new ListNode(1);
    //ListNode * a = new ListNode(3);
    //ListNode * b = new ListNode(8);

    ListNode * l2 = new ListNode(2);
    //ListNode * c = new ListNode(3);
    //ListNode * d = new ListNode(6);

    //l1->next = a;
    //a->next = b;
    //l2->next = c;
    //c->next = d;

    l1 = s.mergeTwoLists(l2,l1);
    while(l1 != NULL){
        cout<<l1->val<<endl;
        l1 = l1->next;
    }
    return 0;
}
