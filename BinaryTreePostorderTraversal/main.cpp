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
	vector<int> postorder;
public:
    vector<int> postorderTraversal(TreeNode* root) {
    	postorderTraversalBinaryTree(root);
        return postorder;
    }

    void postorderTraversalBinaryTree(TreeNode * root){
    	if(root == NULL){
    		return;
    	}
    	postorderTraversalBinaryTree(root->left);
    	postorderTraversalBinaryTree(root->right);
    	postorder.push_back(root->val);
    }
};

int main(){
	Solution s;
	TreeNode *root = new TreeNode(1);
	TreeNode *a = new TreeNode(2);
	TreeNode *b = new TreeNode(3);
	root->right = a;
	a->left = b;
	vector<int> postorder = s.postorderTraversal(root);
	for(int i = 0; i < postorder.size(); i++){
		cout<<postorder[i]<<endl;
	}
	return 0;
}