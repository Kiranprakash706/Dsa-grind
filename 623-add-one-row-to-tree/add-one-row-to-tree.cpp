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
TreeNode* helper(TreeNode* root, int depth ,int level, int val){
 if(root == nullptr) return nullptr;
if(level==depth-1){
    TreeNode* node1=new TreeNode(val);
    TreeNode* node2=new TreeNode(val);
    node1->left=root->left;
    root->left=node1;
    node2->right=root->right;
    root->right=node2;
    return root;
}
else{
    root->left=helper(root->left, depth, level+1, val);
    root->right=helper(root->right, depth, level+1, val);
    return root;
}
}
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* node =new TreeNode(val);
            node->left=root;
            return node;
        }
        return helper(root, depth,1, val);
    }
};