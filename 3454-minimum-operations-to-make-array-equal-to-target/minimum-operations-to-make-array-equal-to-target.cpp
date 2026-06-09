class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        vector<int>diff(nums.size(), 0);
        for(int i=0;i<nums.size();i++){
            diff[i]=target[i]-nums[i];
        }
        long long  ans=0;
        for(int i=0;i<diff.size();i++){
            if(i==0){
                ans+=llabs(diff[i]);
            }
            else{
                long long  temp=max(0ll,llabs(diff[i])-llabs(diff[i-1])*((long long )diff[i]*diff[i-1]>0));
                ans+=temp;
            }
        }
        return ans;
    }
};