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
    bool hasPathSum(TreeNode* root, int sum) {
    	if(root == NULL){
    		return false;
    	}
    	if(sum == root->val && root->left == NULL && root->right == NULL){
    		return true;
    	}

    	if(root->left != NULL){
    		if(hasPathSum(root->left,sum - root->val)){
    			return true;
    		}
    	}

    	if(root->right != NULL){
			if(!hasPathSum(root->right,sum - root->val)){
				return false;
			}else{
				return true;
			}
    	}
    	return false;
    }
};

int main(){
	Solution s;
	TreeNode *root = new TreeNode(-2);
	TreeNode *a = new TreeNode(-3);
	

	root->left = a;
	

	cout<<s.hasPathSum(root,-5)<<endl;
	return 0;
}