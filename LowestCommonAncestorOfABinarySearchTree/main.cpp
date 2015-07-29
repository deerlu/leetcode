#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val){
        	TreeNode * tmp = p;
        	p = q;
        	q = tmp;
        }
        while(root->val < p->val || root->val > q->val){
        	while(root->val < p->val) root= root->right;
        	while(root->val > q->val) root = root->left;
        }
        return root;
    }
};

int main(){
	Solution s;
	TreeNode * root = new TreeNode(6);
	TreeNode * a = new TreeNode(2);
	TreeNode * b = new TreeNode(8);
	TreeNode * c = new TreeNode(0);
	TreeNode * d = new TreeNode(4);
	TreeNode * e = new TreeNode(7);
	TreeNode * f = new TreeNode(9);
	TreeNode * g = new TreeNode(3);
	TreeNode * h = new TreeNode(5);
	root->left = a;
	root->right = b;
	a->left = c;
	a->right = d;
	d->left = g;
	d->right = h;
	b->left = e;
	b->right = f;
	root = s.lowestCommonAncestor(root, d, a);
	cout<<root->val<<endl;
	return 0;
}