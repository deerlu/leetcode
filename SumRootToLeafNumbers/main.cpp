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
private:
	int sum;
public:
    int sumNumbers(TreeNode* root) {
    	if(root == NULL){
    		return 0;
    	}
        sum = 0;
        sumRootToLeaf(root,0);
        return sum;
    }

    void sumRootToLeaf(TreeNode* node, int count){
    	if(node->left != NULL){
    		sumRootToLeaf(node->left, count * 10 + node->val);
    	}
    	if(node->right != NULL){
    		sumRootToLeaf(node->right, count * 10 + node->val);
    	}
    	if(node->left == NULL && node->right == NULL){
    		count = count * 10 + node->val;
    		sum += count;
    	}
    }
};

int main(){
	Solution s;
	TreeNode *root = new TreeNode(4);
	TreeNode *a = new TreeNode(9);
	TreeNode *b = new TreeNode(0);
	TreeNode *c = new TreeNode(1);
	root->left = a;
	root->right = b;
	a->right = c;
	cout<<s.sumNumbers(root)<<endl;
	return 0;
}