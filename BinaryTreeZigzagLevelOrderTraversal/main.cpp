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
    vector< vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector< vector<int> > result;
        if(root == NULL){
        	return result;
        }

        vector<int> row;
        vector<TreeNode*> NodeList;
        row.push_back(root->val);
        NodeList.push_back(root);
        result.push_back(row);

        int start = 0;
        int length = NodeList.size();
        bool leftToRight = false;

        while(true){
        	if(start == length){
        		return result;
        	}
        	row.clear();
	        for(int i = start; i < length;){
	        	if(leftToRight){
	        		if(NodeList[i]->left != NULL){
	        			row.push_back(NodeList[i]->left->val);
	        			NodeList.push_back(NodeList[i]->left);
	        		}
	        		if(NodeList[i]->right != NULL){
	        			row.push_back(NodeList[i]->right->val);
	        			NodeList.push_back(NodeList[i]->right);
	        		}
	        	}else{
	        		if(NodeList[i]->right != NULL){
	        			row.push_back(NodeList[i]->right->val);
	        			NodeList.push_back(NodeList[i]->right);
	        		}
	        		if(NodeList[i]->left != NULL){
	        			row.push_back(NodeList[i]->left->val);
	        			NodeList.push_back(NodeList[i]->left);
	        		}
	        	}
	        }
	        leftToRight = ! leftToRight;
	        start = length;
	        length = NodeList.size();
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
	result = s.zigzagLevelOrder(root);
	for(int i = 0; i < result.size(); i++){
		for(int j = 0; j < result[i].size(); j++){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}