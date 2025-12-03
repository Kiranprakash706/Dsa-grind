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
const int MOD=1e9 + 7;
int totalsum(TreeNode* root){
    if(!root){
        return 0;
    }
    return root->val+totalsum(root->left)+totalsum(root->right);
}
long long  maxxval=INT_MIN;
long long  maxprod(TreeNode* root, int sum){
    if(!root){
        return 0;
    }
    long long currsum=root->val+maxprod(root->left, sum)+maxprod(root->right,sum);
    maxxval=max(maxxval, currsum*(sum-currsum));
    return currsum;
}
    int maxProduct(TreeNode* root) {
        int sum=totalsum(root);
        int product=maxprod(root, sum);
       return maxxval%MOD;
    }
};