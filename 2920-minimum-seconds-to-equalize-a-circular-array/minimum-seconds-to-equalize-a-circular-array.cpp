class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n=nums.size();
        int ans=n;
        unordered_map<int , vector<int>>mapp;
        for(int i=0;i<nums.size();i++){
           mapp[nums[i]].push_back(i);

        }
        for(auto &i:mapp){

            int maxgap=0;
            if (i.second.size() == 1) {
                maxgap = n;
            }
            for(int j=0;j<i.second.size();j++){
                int gap=(i.second[(j+1)%i.second.size()]-i.second[j]+n)%n;
                maxgap=max(maxgap,gap);
            }
            ans = min(ans, maxgap/2);
        }
        return ans;
    }
};