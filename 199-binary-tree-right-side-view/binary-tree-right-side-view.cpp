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
void helper(TreeNode* root,map<int, int >&mapp,int num){
    if(!root){
        return ;
    }
    if(mapp.find(num)==mapp.end()){
        mapp[num]=root->val;
    }
    helper(root->right, mapp, num+1);
    helper(root->left, mapp, num+1);

}
    vector<int> rightSideView(TreeNode* root) {
        if(!root){
            return {};
        }
        map<int , int>mapp;
        mapp[0]=root->val;
        int num=0;
         helper(root->right, mapp, num+1);
         helper(root->left, mapp, num+1);
         vector<int>ans;
         for(auto &i:mapp){
            ans.push_back(i.second);
         }
         return ans;
    }
};