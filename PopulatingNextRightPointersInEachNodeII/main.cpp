#include <iostream>
#include <vector>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
    	vector<TreeLinkNode*> vTreeLinkNode;
    	int start = 0,end = 1,count = 0;
        if(root == NULL){
            return;
        }
        vTreeLinkNode.push_back(root);
        while(start != end){
        	for(int i = start; i < end - 1; i++){
        		vTreeLinkNode[i]->next = vTreeLinkNode[i+1];
        		if(vTreeLinkNode[i] != NULL){
        			if(vTreeLinkNode[i]->left != NULL){
        				vTreeLinkNode.push_back(vTreeLinkNode[i]->left);
        				count++;
        			}
        			if(vTreeLinkNode[i]->right != NULL){
        				vTreeLinkNode.push_back(vTreeLinkNode[i]->right);
        				count++;
        			}
        		}
        	}
        	if(vTreeLinkNode[end-1] != NULL){
        		if(vTreeLinkNode[end-1]->left != NULL){
        			vTreeLinkNode.push_back(vTreeLinkNode[end-1]->left);
        			count++;
        		}
        		if(vTreeLinkNode[end-1]->right != NULL){
        			vTreeLinkNode.push_back(vTreeLinkNode[end-1]->right);
        			count++;
        		}
        	}
        	start = end;
        	end = start + count;
        	count = 0;
        }
    }
};

int main(){
    Solution s;
    TreeLinkNode *root = new TreeLinkNode(1);
    TreeLinkNode *a = new TreeLinkNode(2);
    TreeLinkNode *b = new TreeLinkNode(3);
    TreeLinkNode *c = new TreeLinkNode(4);
    TreeLinkNode *d = new TreeLinkNode(5);
    //TreeLinkNode *e = new TreeLinkNode(6);
    TreeLinkNode *f = new TreeLinkNode(7);
    root->left = a;
    root->right = b;
    a->left = c;
    a->right = d;
    //b->left = e;
    b->right = f;
    s.connect(root);
    cout<<d->next->val<<endl;
    //cout<<d->next->val<<endl;
    //cout<<e->next->val<<endl;
    if(f->next == NULL){
        cout<<"NULL"<<endl;
    }
    return 0;
}