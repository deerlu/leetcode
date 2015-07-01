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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){
            return true;
        }
        if(p == NULL && q != NULL || p != NULL && q == NULL){
            return false;
        }
        if(p->val == q->val){
            if(isSameTree(p->left,q->left)){
                return isSameTree(p->right,q->right);
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
};

int main()
{
    Solution s;
    TreeNode *root1 = new TreeNode(1);
    TreeNode *a = new TreeNode(2);
    TreeNode *b = new TreeNode(3);
    TreeNode *root2 = new TreeNode(1);
    TreeNode *c = new TreeNode(2);
    TreeNode *d = new TreeNode(3);
    TreeNode *e = new TreeNode(3);
    root1->left = a;
    root1->right = b;
    root2->left = c;
    root2->right = d;
    d->left = e;
    cout<<s.isSameTree(NULL,root2);
    return 0;
}
