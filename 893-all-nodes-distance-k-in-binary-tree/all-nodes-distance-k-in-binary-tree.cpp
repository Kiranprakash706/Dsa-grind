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
void helper(TreeNode* root,unordered_map<TreeNode*, TreeNode* >&parent_track){
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int sizee=q.size();
        TreeNode* curr=q.front();
        q.pop();
       
            if(curr->left){
                q.push(curr->left);
                parent_track[curr->left]=curr;
            }
            if(curr->right){
                q.push(curr->right);
                parent_track[curr->right]=curr;
            }
        
    }

}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*>parent_track;
        helper(root, parent_track);
        vector<int>ans;
        unordered_map<TreeNode* , bool>visited;
        queue<pair<TreeNode* , int>>q;
        q.push({target, k});
        visited[target]=true;
        while(!q.empty()){
            int sizee=q.size();
            for(int i=0;i<sizee;i++){
                pair<TreeNode* , int> pp=q.front();
                q.pop();
                if(pp.second==0){
                    ans.push_back(pp.first->val);
                }
                if(pp.first->left && !visited[pp.first->left]){
                    q.push({pp.first->left, pp.second-1});
                    visited[pp.first->left]=true;
                }
                if(pp.first->right && !visited[pp.first->right]){
                    q.push({pp.first->right,pp.second-1});
                    visited[pp.first->right]=true;
                }
                if(parent_track.find(pp.first)!=parent_track.end() &&!visited[parent_track[pp.first]] ){
                    q.push({parent_track[pp.first], pp.second-1});
                    visited[parent_track[pp.first]]=true;
                }
            }
        }
        return ans;
    }
};