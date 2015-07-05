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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
        	return true;
        }
        return isEqualNode(root->left, root->right);
    }

    bool isEqualNode(TreeNode* leftNode, TreeNode* rightNode){
    	if(leftNode == NULL && rightNode == NULL){
    		return true;
    	}
    	if(leftNode == NULL || rightNode == NULL){
    		return false;
    	}
    	if(leftNode->val == rightNode->val){
    		if(isEqualNode(leftNode->left, rightNode->right)){
    			if(isEqualNode(leftNode->right, rightNode->left)){
    				return true;
    			}else{
    				return false;
    			}
    		}else{
    			return false;
    		}
    	}else{
    		return false;
    	}
    }
};

int main(){
	Solution s;
	TreeNode *root = new TreeNode(1);
	TreeNode *a = new TreeNode(2);
	TreeNode *b = new TreeNode(2);
	TreeNode *c = new TreeNode(2);
	TreeNode *d = new TreeNode(4);
	TreeNode *e = new TreeNode(4);
	TreeNode *f = new TreeNode(2);

	root->left = a;
	root->right = b;
	a->left = c;
	a->right = d;
	b->left = e;
	b->right = f;

	cout<<s.isSymmetric(root)<<endl;
	return 0;
}