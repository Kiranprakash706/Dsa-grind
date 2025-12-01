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
TreeNode* buildbst(vector<int>&preorder, int prestart, int preend, vector<int>&inorder, int innstart, int innend, unordered_map<int , int >&mapp){
    if(prestart>preend|| innstart>innend){
        return NULL;
    }
    int position=mapp[preorder[prestart]];
    int sizee=position-innstart;
    TreeNode* root=new TreeNode(preorder[prestart]);
    root->left=buildbst(preorder, prestart+1, prestart+sizee,inorder, innstart, position-1, mapp);
    root->right=buildbst(preorder, prestart+sizee+1, preend, inorder, position+1, innend, mapp);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()!=inorder.size()){
            return NULL;
        }
        unordered_map<int , int >mapp;
        for(int i=0;i<inorder.size();i++){
            mapp[inorder[i]]=i;
        }
        TreeNode* root=buildbst(preorder,0, preorder.size()-1, inorder, 0, inorder.size()-1, mapp);
        return root;

    }
};