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
    TreeNode* invertTree(TreeNode* root) {
        exchangeNode(root);
        return root;
    }

    void exchangeNode(TreeNode* node){
    	if(node == NULL){
    		return;
    	}
    	exchangeNode(node->left);
    	exchangeNode(node->right);
    	TreeNode *tmp = node->left;
    	node->left = node->right;
    	node->right = tmp;
    }
};

int main(){
	Solution s;
	TreeNode *root = new TreeNode(4);
	TreeNode *a = new TreeNode(2);
	TreeNode *b = new TreeNode(7);
	TreeNode *c = new TreeNode(1);
	TreeNode *d = new TreeNode(3);
	TreeNode *e = new TreeNode(6);
	TreeNode *f = new TreeNode(9);
	root->left = a;
	root->right = b;
	a->left = c;
	a->right = d;
	b->left = e;
	b->right = f;
	root = s.invertTree(root);
	cout<<root->val<<endl;
	cout<<root->left->val<<endl;
	cout<<root->right->val<<endl;
	cout<<root->left->left->val<<endl;
	cout<<root->left->right->val<<endl;
	cout<<root->right->left->val<<endl;
	cout<<root->right->right->val<<endl;
	return 0;
}