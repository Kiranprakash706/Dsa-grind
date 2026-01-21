class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int ans=0;
        int sum=0;
       for(auto &it:m){
            if(it.second>ans){
                ans=it.second;
                sum=it.second;
            }
            else if(it.second==ans){
                sum+=it.second;
                
            }
       }
       return sum;
    }
};