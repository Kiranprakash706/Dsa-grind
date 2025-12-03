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
int maxval=INT_MIN;
int helper(TreeNode* root){
    if(!root){
        return 0;
    }
    int leftii=max(0,helper(root->left));
    int rightii=max(0,helper(root->right));
    maxval=max(maxval,root->val+leftii+rightii);
    return root->val+max(leftii, rightii);

}
    int maxPathSum(TreeNode* root) {
        int a= helper(root);
        return maxval;
    }
};