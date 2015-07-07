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
    vector< vector<int> > levelOrderBottom(TreeNode* root) {
        vector< vector<int> > result;
        vector<int> row;
        vector< vector<TreeNode*> > vvTreeNode;
        vector<TreeNode*> vTreeNode;
        if(root == NULL){
        	return result;
        }
        vTreeNode.push_back(root);
        vvTreeNode.push_back(vTreeNode);
        while(true){
        	vTreeNode.clear();
        	int length = vvTreeNode[vvTreeNode.size() - 1].size();
        	for(int i = 0; i != length; i++){
        		TreeNode* tmp = vvTreeNode[vvTreeNode.size() - 1][i];
        		if(tmp->left != NULL){
        			vTreeNode.push_back(tmp->left);
        		}
        		if(tmp->right != NULL){
        			vTreeNode.push_back(tmp->right);
        		}
        	}

        	if(vTreeNode.size() == 0){
        		break;
        	}
        	vvTreeNode.push_back(vTreeNode);
        }
        for(int i = vvTreeNode.size() - 1; i >= 0; i--){
        	row.clear();
        	for(int j = 0; j != vvTreeNode[i].size(); j++){
        		row.push_back(vvTreeNode[i][j]->val);
        	}
        	result.push_back(row);
        }
        return result;
    }
};

int main(){
	Solution s;
	vector< vector<int> > result;
	TreeNode * root = new TreeNode(3);
	TreeNode * a = new TreeNode(9);
	TreeNode * b = new TreeNode(20);
	TreeNode * c = new TreeNode(15);
	TreeNode * d = new TreeNode(7);
	root->left = a;
	root->right = b;
	b->left = c;
	b->right = d;
	result = s.levelOrderBottom(root);
	for(int i = 0; i < result.size(); i++){
		for(int j = 0; j < result[i].size(); j++){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}