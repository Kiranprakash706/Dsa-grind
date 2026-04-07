class Solution {
public:
class Node{
    public:
    int data;
    int r;
    int c;
    Node(int data, int r, int c){
        this->data=data;
        this->r=r;
        this->c=c;

    }
};
class compare{
public:
bool operator()(Node* a, Node* b){
    return a->data>b->data;
}
};
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        vector<int>ans;
        priority_queue<Node*, vector<Node*>, compare>pq;

        for(int i=0;i<nums.size();i++){
            Node* temp=new Node(nums[i][0],i,0);
            pq.push(temp);
            maxi=max(maxi, nums[i][0]);
            mini=min(mini, nums[i][0]);
        }
        int start=mini;
        int end=maxi;
        while(!pq.empty()){
            Node* temp=pq.top();
            pq.pop();
            mini=temp->data;
            if(maxi-mini<end-start){
                start=mini;
                end=maxi;

            }
            if(temp->c+1<nums[temp->r].size()){
                pq.push(new Node(nums[temp->r][temp->c+1], temp->r, temp->c+1));
                 maxi=max(maxi,nums[temp->r][temp->c+1] );
                
            }
            else{//ye else block iss liye hai kyu ki hmlog ko 1 element from each list chahiye toh agar pq.size()!=nums.size() huii to humme simply break kar jana hai
                break;
            }
            
        }
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};