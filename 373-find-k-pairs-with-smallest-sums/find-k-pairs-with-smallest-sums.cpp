class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int ,pair<int, int>>>pq;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                int sum=nums1[i]+nums2[j];
                if(pq.size() < k){
                    pq.push({sum, {i, j}});
                }
                else if(pq.top().first > sum){
                    pq.pop();
                    pq.push({sum, {i, j}});
                }
                else{
                    break;
                }
            }
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            int a=nums1[pq.top().second.first];
            int b=nums2[pq.top().second.second];
            vector<int> temp;
            temp.push_back(a);
            temp.push_back(b);
            ans.push_back(temp);
            pq.pop();

        }
        return ans;
    }
};