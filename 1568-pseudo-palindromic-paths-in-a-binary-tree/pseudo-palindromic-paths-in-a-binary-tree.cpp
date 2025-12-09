class Solution {
public:
    int count = 0;

    bool check(unordered_map<int, int>& mapp) {
        int cnt = 0;
        for (auto& i : mapp) {
            if (i.second % 2 != 0) cnt++;
            if (cnt > 1) return false;
        }
        return true;
    }

    void helper(TreeNode* root, unordered_map<int, int>& mapp) {
        if (!root){
            return ;
        } 
        mapp[root->val]++;
        if (!root->left && !root->right) {
            if (check(mapp)){
                count++;
            } 
        }

        helper(root->left,mapp);
        helper(root->right,mapp);

        mapp[root->val]--; 
        if (mapp[root->val] == 0){
                mapp.erase(root->val);
        } 
    }
    int pseudoPalindromicPaths(TreeNode* root) {
        unordered_map<int, int> mapp;
        helper(root, mapp);
        return count;
    }
};
