#include <iostream>
#include <vector>
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
private:
	vector<int> inorder;
public:
    vector<int> inorderTraversal(TreeNode* root) {
    	recursiveTraversal(root);
        return inorder;
    }

    void recursiveTraversal(TreeNode* node){
    	if(node == NULL){
    		return;
    	}
    	recursiveTraversal(node->left);
    	inorder.push_back(node->val);
    	recursiveTraversal(node->right);
    }
};

int main(){
	Solution s;
	vector<int> inorder;
	TreeNode *root = new TreeNode(1);
	TreeNode *a = new TreeNode(2);
	TreeNode *b = new TreeNode(3);
	TreeNode *c = new TreeNode(4);
	TreeNode *d = new TreeNode(5);
	root->right = a;
	//root->right = b;
	a->left = b;
	//b->left = d;
	inorder = s.inorderTraversal(root);
	for(int i = 0; i < inorder.size(); i++){
		cout<<inorder[i]<<endl;
	}
	return 0;
}