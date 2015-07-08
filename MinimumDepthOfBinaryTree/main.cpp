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
	int minD;
public:
    int minDepth(TreeNode* root) {
        if(root == NULL){
        	return 0;
        }
        minD = INT_MAX;
        searchMinDepth(root, 1);
        return minD;
    }

    void searchMinDepth(TreeNode* node, int depth){
    	if(node->left == NULL && node->right == NULL){
    		if(minD > depth){
    			minD = depth;
    		}
    	}else{
    		if(node->left != NULL){
    			searchMinDepth(node->left, depth + 1);
    		}
    		if(node->right != NULL){
    			searchMinDepth(node->right, depth + 1);
    		}
    	}
    }
};

int main(){
	Solution s;
	TreeNode * root = new TreeNode(1);
	TreeNode * a = new TreeNode(2);
	TreeNode * b = new TreeNode(3);
	TreeNode * c = new TreeNode(4);
	root->left = a;
	root->right = b;
	a->left = c;

	cout<<s.minDepth(root)<<endl;
	return 0;
}