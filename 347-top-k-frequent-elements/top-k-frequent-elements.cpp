class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int , int > mapp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            mapp[nums[i]]++;
            
        }
       priority_queue<pair<int, int>, vector<pair<int , int >>, greater<pair<int , int >>>pq;
       for(auto &i:mapp){
        if(pq.size()<k){
            pq.push({i.second,i.first});
        }
        else{
            if(pq.top().first<i.second){
                pq.pop();
                pq.push({i.second, i.first});
            }
        }
       }
       while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
       }
       return ans;

    }
};