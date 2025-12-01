/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int count(TreeNode* root){
     if(!root){
        return 0;
     }
     return 1+count(root->left)+count(root->right);
}
bool check(TreeNode* root, int index, int total){
    if(!root){
        return true;
    }
    if(index>=total){
        return false;
    }
    bool leftii=check(root->left, 2*index+1, total);
    bool rightii=check(root->right, 2* index+2, total);
    return leftii && rightii;
}
    bool isCompleteTree(TreeNode* root) {
        int total=count(root);
        return check(root,0, total);

    }
};