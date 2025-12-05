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
int maxsize=0;
    void helper(TreeNode* root, int sizee, char ch){
        
        if(!root){
            return;
        }
        maxsize=max(maxsize, sizee);
        if(ch=='r'){
            helper(root->left, sizee+1,'l');
            helper(root->right, 1,'r');
        }
        else if(ch=='l'){
            helper(root->right, sizee+1, 'r');
            helper(root->left, 1, 'l');
        }
        else{
            helper(root->right, sizee+1, 'r');
            helper(root->left, sizee+1, 'l');
        }
    }
    int longestZigZag(TreeNode* root) {
        helper(root, 0, 'u');
        return maxsize;
    }
};