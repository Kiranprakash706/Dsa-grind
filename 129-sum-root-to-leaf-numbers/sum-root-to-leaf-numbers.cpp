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
long long sum=0;
void helper(TreeNode* root, long long  value){
    if(!root){
        return;
    }
    if(!root->left &&!root->right){
        sum+=(value*10+root->val);
    }
    helper(root->left, value*10+root->val);
    helper(root->right, value*10+root->val);
}
    int sumNumbers(TreeNode* root) {
        helper(root,0);
        return sum;
    }
};