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
// int time=0;
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
TreeNode* dfs(TreeNode* root,int start){
    if(!root){
        return NULL;
    }
    if(root->val==start){
        return root;
    }
    TreeNode* leftii=dfs(root->left, start);
    TreeNode* righti=dfs(root->right,start);
    if(leftii!=NULL && righti==NULL){
        return leftii;
    }
    else{
        return righti;
    }
}
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode* , TreeNode*>parent_track;
        helper(root, parent_track);
        unordered_map<TreeNode* , bool>visited;
        queue<pair<TreeNode*, int >>q;
        TreeNode* ans=dfs(root, start);
        q.push({ans,0});
        visited[ans]=true;
        int a=-1;
        while(!q.empty()){
           int sizee=q.size();
       
            for(int i=0;i<sizee;i++){
                pair<TreeNode*, int>po=q.front();
                TreeNode*curr=po.first;
                int time=po.second;
                q.pop();
            if(curr->left && visited[curr->left]==false){
                q.push({curr->left,time+1});
                visited[curr->left]=true;
            }
            if(curr->right && visited[curr->right]==false){
                q.push({curr->right, time +1});
                visited[curr->right]=true;
            }
            if(parent_track.find(curr)!=parent_track.end() && !visited[parent_track[curr]]){
                q.push({parent_track[curr],time+1});
                visited[parent_track[curr]]=true;
            }
             a=time;
            }
           
           
        }
        return a;
    }
};