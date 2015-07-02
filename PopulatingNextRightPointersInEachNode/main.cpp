#include <iostream>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
    	if(root == NULL){
    		return;
    	}
        connectLeftAndRight(root->left,root->right);
    }

    void connectLeftAndRight(TreeLinkNode *leftNode, TreeLinkNode *rightNode){
    	if(leftNode == NULL){
    		return;
    	}
    	if(rightNode == NULL){
    		return;
    	}
    	leftNode->next = rightNode;
    	connectLeftAndRight(leftNode->left,leftNode->right);
    	connectLeftAndRight(leftNode->right,rightNode->left);
    	connectLeftAndRight(rightNode->left,rightNode->right);
    }
};

int main(){
	Solution s;
	TreeLinkNode *root = new TreeLinkNode(1);
	TreeLinkNode *a = new TreeLinkNode(2);
	TreeLinkNode *b = new TreeLinkNode(3);
	TreeLinkNode *c = new TreeLinkNode(4);
	TreeLinkNode *d = new TreeLinkNode(5);
	TreeLinkNode *e = new TreeLinkNode(6);
	TreeLinkNode *f = new TreeLinkNode(7);
	root->left = a;
	root->right = b;
	a->left = c;
	a->right = d;
	b->left = e;
	b->right = f;
	s.connect(root->left);
	cout<<c->next->val<<endl;
	//cout<<d->next->val<<endl;
	//cout<<e->next->val<<endl;
	if(b->next == NULL){
		cout<<"NULL"<<endl;
	}
	return 0;
}