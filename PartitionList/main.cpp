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
    ListNode* partition(ListNode* head, int x) {
        ListNode* firstGreaterNode = head,*beforeFirst = head;
        while(firstGreaterNode != NULL && firstGreaterNode->val < x){
            beforeFirst = firstGreaterNode;
            firstGreaterNode = firstGreaterNode->next;
        }
        bool tag = false;
        if(firstGreaterNode == head){
            tag = true;
        }
        if(firstGreaterNode != NULL){
            ListNode* p = firstGreaterNode->next;
            ListNode* beforeP = firstGreaterNode;
            while(p != NULL){
                if(p->val < x){
                    beforeP->next = p->next;
                    if(!tag){
                        beforeFirst->next = p;
                    }else{
                        head = p;
                        tag = false;
                    }
                    p->next = firstGreaterNode;
                    beforeFirst = p;
                    p = beforeP->next;
                }else{
                    beforeP = p;
                    p = p->next;
                }
            }
        }
        return head;
    }
};

int main(){
    Solution s;
    ListNode* head = new ListNode(2);
    ListNode* a = new ListNode(1);
    head->next = a;
    head = s.partition(head,2);
    while(head != NULL){
        cout<<head->val<<endl;
        head = head->next;
    }
    return 0;
}