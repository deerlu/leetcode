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
    int maxD;
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        maxD = 1;
        calMaxDepth(root,maxD);
        return maxD;
    }

    void calMaxDepth(TreeNode * root, int depth){
        if(depth > maxD){
            maxD = depth;
        }

        if(root == NULL){
            return;
        }
        if(root->left){
            calMaxDepth(root->left,depth+1);
        }
        if(root->right){
            calMaxDepth(root->right,depth+1);
        }
    }
};

int main()
{
    Solution s;
    TreeNode* root = new TreeNode(1);
    TreeNode* a = new TreeNode(2);
    TreeNode* b = new TreeNode(3);
    TreeNode* c = new TreeNode(3);
    root->left = a;
    a->left = b;
    a->right = c;
    cout<<s.maxDepth(root)<<endl;
    return 0;
}
