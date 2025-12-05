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
    int minDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            return 1;
        }
        int leftii=minDepth(root->left);
        int rightii=minDepth(root->right);
        if(leftii==0){
            return rightii+1;
        }
        if(rightii==0){
            return leftii+1;
        }
        return min(leftii, rightii)+1;
    }
};