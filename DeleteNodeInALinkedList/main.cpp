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
    void deleteNode(ListNode* node) {
        if(node == NULL){
            return;
        }
        ListNode * preNode;
        preNode = node;
        while(node->next != NULL){
            node->val = node->next->val;
            preNode = node;
            node = node->next;
        }
        preNode->next = NULL;
        delete node;
    }
};

int main(){
    Solution s;
    ListNode * head = new ListNode(1);
    ListNode * a = new ListNode(2);
    ListNode * b = new ListNode(3);
    ListNode * c = new ListNode(4);
    ListNode * d = new ListNode(5);
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    s.deleteNode(head);
    while(head != NULL){
        cout<<head->val<<endl;
        head = head->next;
    }
    return 0;
}