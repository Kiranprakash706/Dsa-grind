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
int helper(TreeNode* root, int maxval, int minval){
    if(!root){
        return abs(maxval-minval);
    }
    int lefti=helper(root->left, max(root->val,maxval), min(root->val,  minval));
    int righti=helper(root->right, max(root->val,maxval), min(root->val, minval));
    return max(lefti, righti);
}
    int maxAncestorDiff(TreeNode* root) {
        return helper(root, root->val, root->val);
    }
};