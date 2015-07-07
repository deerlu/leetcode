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
public:
    vector< vector<int> > levelOrder(TreeNode* root) {
        vector< vector<int> > result;
        vector<TreeNode*> vTreeNode;
        vector<int> row;
    	int start = 0,end = 1,count = 0;
        if(root == NULL){
            return result;
        }
        
        vTreeNode.push_back(root);
        while(start != end){
        	row.clear();
        	for(int i = start; i < end; i++){
        		row.push_back(vTreeNode[i]->val);
        		if(vTreeNode[i] != NULL){
        			if(vTreeNode[i]->left != NULL){
        				vTreeNode.push_back(vTreeNode[i]->left);
        				count++;
        			}
        			if(vTreeNode[i]->right != NULL){
        				vTreeNode.push_back(vTreeNode[i]->right);
        				count++;
        			}
        		}
        	}
        	
        	start = end;
        	end = start + count;
        	count = 0;
        	result.push_back(row);
        }
        return result;
    }
};

int main(){
	Solution s;
	TreeNode *root = new TreeNode(3);
	TreeNode *a = new TreeNode(9);
	TreeNode *b = new TreeNode(20);
	TreeNode *c = new TreeNode(15);
	TreeNode *d = new TreeNode(7);
	root->left = a;
	root->right = b;
	b->left = c;
	b->right = d;

	vector< vector<int> > v = s.levelOrder(root);
	for(int i = 0; i < v.size(); i++){
		for(int j = 0; j < v[i].size(); j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}