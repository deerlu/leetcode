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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        vector<TreeNode*> prev,now;
        if(root == NULL){
        	return result;
        }
        prev.push_back(root);
        result.push_back(root->val);
        while(true){
	        for(int i = 0; i < prev.size(); i++){
	        	TreeNode* tmp = prev[i];
	        	if(tmp->left != NULL){
	        		now.push_back(tmp->left);
	        	}
	        	if(tmp->right != NULL){
	        		now.push_back(tmp->right);
	        	}
	        }
        	prev = now;
        	if(now.size() > 0){
        		result.push_back(now[now.size() - 1]->val);
        	}else{
        		return result;
        	}
        	now.clear();
    	}
    }
};

int main(){
	Solution s;
	TreeNode* root = new TreeNode(1);
	TreeNode* a = new TreeNode(2);
	TreeNode* b = new TreeNode(3);
	TreeNode* c = new TreeNode(5);
	TreeNode* d = new TreeNode(4);
	root->left = a;
	root->right = b;
	a->right = c;
	b->right = d;
	vector<int> result = s.rightSideView(root);
	for(int i = 0; i < result.size(); i++){
		cout<<result[i]<<endl;
	}
	return 0;
}