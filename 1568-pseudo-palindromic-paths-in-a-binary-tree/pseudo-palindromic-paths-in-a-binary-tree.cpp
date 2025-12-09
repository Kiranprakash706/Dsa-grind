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
    int res = 0;
    void dfs(TreeNode* node, vector<int>& freq) {
        if (!node) return;
        freq[node->val]++;
        // If it's a leaf node
        if (!node->left && !node->right) {
            int odd = 0;
            for (int i = 1; i <= 9; ++i) {
                if (freq[i] % 2 != 0) odd++;
            }
            if (odd <= 1) res++;
        }
        dfs(node->left, freq);
        dfs(node->right, freq);
        freq[node->val]--; // backtrack
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freq(10, 0); // digit values 1-9
        dfs(root, freq);
        return res;
    }
};