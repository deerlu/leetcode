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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *p = head->next, *nextNode = head,*prevNode = head;
        while(nextNode != NULL){
            nextNode = p->next;
            p->next = prevNode;
            prevNode = p;
            p = nextNode;
        }
        head->next = NULL;
        return prevNode;
    }
};

int main()
{
    Solution s;
    ListNode * head = new ListNode(1);
    ListNode * a = new ListNode(2);
    ListNode * b = new ListNode(3);
    ListNode * c = new ListNode(4);
    head->next = a;
    a->next = b;
    b->next = c;
    head = s.reverseList(head);
    while(head != NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
    return 0;
}
