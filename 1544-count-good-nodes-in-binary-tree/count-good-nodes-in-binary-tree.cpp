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
int cnt=0;
void helper(TreeNode* root, int maxval){
    if(!root){
        return ;
    }
    if(!root->left && !root->right){
        if(root->val>=maxval){
            cnt++;
            return;
        }
    }
    if(maxval<=root->val){
        cnt++;
        helper(root->left, root->val);
        helper(root->right,root->val);
    }
    else{
        helper(root->left, maxval);
        helper(root->right, maxval);
    }
}
    int goodNodes(TreeNode* root) {
        helper(root,root->val);
        return cnt;
    }
};