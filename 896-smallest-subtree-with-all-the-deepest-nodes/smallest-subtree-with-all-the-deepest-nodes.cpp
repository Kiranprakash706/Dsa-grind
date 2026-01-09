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
pair<int, TreeNode*>helper(TreeNode* root){
    if(!root){
        return {1,NULL};
    }
    pair<int , TreeNode*>left=helper(root->left);
    pair<int , TreeNode*>right=helper(root->right);
    if(left.first==right.first){
        return{left.first+1, root};
    }
    else if(left.first>right.first){
        return {left.first+1,left.second};
    }
    else{
        return {right.first+1, right.second};
    }

}
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        pair<int , TreeNode*>ans= helper(root);
        return ans.second;
    }
};
