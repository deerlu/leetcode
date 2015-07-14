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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *first,*second,*startM,*endN;
        int count = 1;
        ListNode* start = new ListNode(1);
        start->next = head;
        first = start;
        second = head;
        while(second != NULL){
            if(count == m){
                startM = first;
                first = second;
                second = second->next;
            }else if(count > m && count < n){
                ListNode *tmp = second->next;
                second->next = first;
                first = second;
                second = tmp;
            }else if(count == n){
                endN = second->next;
                second->next = first;
                startM->next->next = endN;
                startM->next = second;
                break;
            }else{
                first = second;
                second = second->next;
            }
            count++;
        }
        ListNode*tmp = start->next;
        delete start;
        return tmp;
    }
};

int main(){
    Solution s;
    ListNode* head = new ListNode(1);
    ListNode* a = new ListNode(2);
    ListNode* b = new ListNode(3);
    ListNode* c = new ListNode(4);
    ListNode* d = new ListNode(5);
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    head = s.reverseBetween(head,1,4);
    while(head != NULL){
        cout<<head->val<<endl;
        head = head->next;
    }
    return 0;
}