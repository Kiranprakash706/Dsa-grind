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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        long long width=0;
        long long diff=0;
        queue<pair<TreeNode* , long long >>pq;
        pq.push({root, 0});

        while(!pq.empty()){
            int sizee=pq.size();
            pair<TreeNode* , long long>w=pq.front();
            long long respect_index=w.second;
            long long firsti, lastii;

            for(int i=0;i<sizee;i++){
                pair<TreeNode* , long long >pp=pq.front();
                long long  ind=pp.second;
                TreeNode* node=pp.first;
                ind =ind-respect_index;
                pq.pop();
                if(i==0){
                    firsti=ind;
                }
                if(i==sizee-1){
                    lastii=ind;
                }
                if(node->left){
                    pq.push({node->left,2*ind+1});
                }
                if(node->right){
                    pq.push( {node->right, 2*ind+2});
                }
            }
            diff=lastii-firsti+1;
            width=max(width,diff);

        }
        return width;
    }
};