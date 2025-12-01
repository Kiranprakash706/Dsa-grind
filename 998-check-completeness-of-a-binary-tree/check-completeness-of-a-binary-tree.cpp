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
    bool isCompleteTree(TreeNode* root) {
        if(!root){
            return true;
        }
        queue<TreeNode*>q;
        q.push(root);
        bool check=false;
        while(!q.empty()){
            TreeNode* a=q.front();
            q.pop();
            if(a==NULL){
                check=true;
            }
            else{
                if(check){
                    return false;
                }
                q.push(a->left);
                q.push(a->right);
            }
        }
        return true;
    }
};