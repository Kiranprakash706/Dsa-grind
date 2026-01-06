class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        
        int maxSum = INT_MIN;
        int resultLevel = 1;
        
        while(!q.empty()) {
            int size = q.size();
            int sum = 0;
            int currentLevel = q.front().second;
            
            for(int i = 0; i < size; i++) {
                auto p = q.front();
                q.pop();
                
                TreeNode* node = p.first;
                int lvl = p.second;
                
                sum += node->val;
                
                if(node->left) q.push({node->left, lvl + 1});
                if(node->right) q.push({node->right, lvl + 1});
            }
            
            if(sum > maxSum) {
                maxSum = sum;
                resultLevel = currentLevel;
            }
        }
        
        return resultLevel;
    }
};
