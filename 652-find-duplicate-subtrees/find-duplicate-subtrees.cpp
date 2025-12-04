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
unordered_map<string , int >mapp;
vector<TreeNode* >ans;
string helper(TreeNode* root){
if(!root){
    return "" ;
}
string s=to_string(root->val)+','+helper(root->left)+','+ helper(root->right);
mapp[s]++;
if(mapp[s]==2){
    ans.push_back(root);
}
return s;
}
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
         helper(root);
        return ans;
    }
};