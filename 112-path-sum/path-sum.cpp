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
bool helper(TreeNode* root, int targetsum){
     if(!root){
        return false;
     }
     if(!root->left && !root->right && targetsum-root->val==0){
        return true;
     }
   
    bool leftsum=helper(root->left,targetsum-root->val);
    bool rightsum=helper(root->right,targetsum-root->val);
    return leftsum|| rightsum;
}
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){
            return false;
        }
        return helper(root, targetSum);
    }
};