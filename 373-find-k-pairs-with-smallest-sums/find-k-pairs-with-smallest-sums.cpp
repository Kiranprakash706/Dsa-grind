class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
       priority_queue<tuple<int , int, int>, vector<tuple<int, int , int>>, greater<tuple<int , int , int>>>pq;

       for(int i=0;i<nums1.size() && i<k ;i++){
        pq.emplace(nums1[i]+nums2[0], i, 0);
       }
        vector<vector<int>>ans;
        while(k-- && !pq.empty()){
            auto[sum, i, j]=pq.top();
            int a=nums1[i];
            int b=nums2[j];
            vector<int> temp;
            temp.push_back(a);
            temp.push_back(b);
            ans.push_back(temp);
            pq.pop();
            if(j+1<nums2.size()){
                pq.emplace(nums2[j+1]+nums1[i], i, j+1);
            }

        }
        return ans;
    }
};