/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root||!p || !q){
            return NULL;
        }
        if(root->val==p->val ){
            return p;
        }
        if(root->val==q->val){
            return q;
        }
        if(root->val!=p->val && root->val!=q->val){
            TreeNode* lefttree=lowestCommonAncestor(root->left, p, q);
            TreeNode* righttree=lowestCommonAncestor(root->right, p, q);
            if(lefttree!=NULL &&righttree!=NULL){
                return root;
            }
            if(lefttree!=NULL && righttree==NULL){
                return lefttree;
            }
            if(righttree!=NULL && lefttree==NULL){
                return righttree;
            }
            else{
                return NULL;
            }
        }
        return NULL;
    }
};