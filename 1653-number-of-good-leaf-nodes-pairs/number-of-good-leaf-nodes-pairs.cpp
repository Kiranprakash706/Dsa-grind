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
vector<int>dfs(TreeNode* root, int distance, int &res){
    if(!root){
        return {};

    }
    if(!root->left && !root->right){
        return{1};
    }
    vector<int >left=dfs(root->left, distance, res);
    vector<int> right=dfs(root->right, distance,res);
    for(int i:left){
        for(int j:right){
            if(i+j<=distance){
                res++;
            }
        }
    }
    vector<int> curr;
    for(int i:left){
        if(i+1<=distance)curr.push_back(i+1);
    }
    for(int i:right){
        if(i+1<=distance)curr.push_back(i+1);
    }
    return curr;
}
    int countPairs(TreeNode* root, int distance) {
        int res=0;
        dfs(root, distance, res);
        return res;
    }
};