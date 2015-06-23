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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0,pos;
        ListNode *p = head,*prev;
        while(p != NULL){
            length++;
            p = p->next;
        }
        if(length == 0 || length == 1){
            return NULL;
        }
        pos = length - n;
        if(pos == 0){
            p = head->next;
            delete head;
            return p;
        }
        prev = head;
        for(int i = 0; i < pos-1; i++){
            prev = prev->next;
        }
        p = prev->next->next;
        delete prev->next;
        prev->next = p;
        return head;
    }
};

int main()
{
    Solution s;
    ListNode * head = new ListNode(1);
    ListNode * a = new ListNode(2);
    ListNode * b = new ListNode(4);
    head->next = a;
    a->next = b;

    head = s.removeNthFromEnd(head,1);
    while(head != NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
    return 0;
}
