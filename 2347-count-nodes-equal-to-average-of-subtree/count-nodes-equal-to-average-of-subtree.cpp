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
int total=0;
    pair<int, int >dfs(TreeNode* root){
        if(!root){
            return {0,0};
        }
        auto left=dfs(root->left);
        auto right=dfs(root->right);
        int value=root->val+left.first+right.first;
        int nodes=1+left.second+right.second;
        if(value/nodes==root->val){
            total++;
        }
        return {value, nodes};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return total;
    }
};