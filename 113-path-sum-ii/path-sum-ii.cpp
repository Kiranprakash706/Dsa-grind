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
void helper(TreeNode* root, int target,vector<int >temp, vector<vector<int>>&ans){
    if(!root){
        return ;
    }
    if(!root->left && !root->right && target-root->val==0){
        temp.push_back(root->val);
        ans.push_back(temp);
    }
    
    
    temp.push_back(root->val);
    helper(root->left, target-root->val, temp, ans);
    helper(root->right, target-root->val,temp, ans);

}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return {};
        }
        vector<vector<int>>ans;
        vector<int>temp;
        helper(root, targetSum, temp, ans);
        return ans;
    }
};