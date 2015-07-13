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
	vector< vector<int> > result;
	vector<int> path;
public:
    vector< vector<int> > pathSum(TreeNode* root, int sum) {
    	findPathSum(root, sum);
    	return result;
    }

    void findPathSum(TreeNode* root, int sum){
    	if(root == NULL){
    		return ;
    	}
    	path.push_back(root->val);
    	if(sum == root->val && root->left == NULL && root->right == NULL){
    		result.push_back(path);
    		return ;
    	}

    	if(root->left != NULL){
    		findPathSum(root->left,sum - root->val);
    		path.erase(path.end() - 1);
    	}

    	if(root->right != NULL){	
			findPathSum(root->right,sum - root->val);
			path.erase(path.end() - 1);
    	}
    }
};

int main(){
	Solution s;
	TreeNode *root = new TreeNode(5);
	TreeNode *a = new TreeNode(4);
	TreeNode *b = new TreeNode(8);
	TreeNode *c = new TreeNode(11);
	TreeNode *d = new TreeNode(13);
	TreeNode *e = new TreeNode(4);
	TreeNode *f = new TreeNode(7);
	TreeNode *g = new TreeNode(2);
	TreeNode *h = new TreeNode(5);
	TreeNode *i = new TreeNode(1);
	root->left = a;
	root->right = b;
	a->left = c;
	b->left = d;
	b->right = e;
	c->left = f;
	c->right = g;
	e->left = h;
	e->right = i;
	vector< vector<int> > v;
	v = s.pathSum(root,22);
	for(int i = 0; i < v.size(); i++){
		for(int j = 0; j < v[i].size(); j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}