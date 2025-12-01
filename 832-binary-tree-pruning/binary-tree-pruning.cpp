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
TreeNode* todeleted(TreeNode* root){
    if(!root){
        return NULL;
    }
    root->left=todeleted(root->left);
    root->right=todeleted(root->right);
    if(root->val!=1){
        if(!root->left && !root->right){
            return NULL;
        }
        return root;
    }
    else{
        return root;
    }
}
    TreeNode* pruneTree(TreeNode* root) {
        if(!root){
            return NULL;
        }
       TreeNode* node= todeleted(root);
        return node;
    }
};