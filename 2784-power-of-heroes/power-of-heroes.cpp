class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        int MOD=1000000007;
        long long  prefix=0;
        sort(nums.begin(), nums.end());
        long long ans=0;

        for(int i=0;i<nums.size();i++){
            ans+=(((long long)nums[i]*nums[i]%MOD)*(nums[i]+prefix)%MOD)%MOD;
            prefix=(prefix*2%MOD+nums[i])%MOD;

        }
        return ans%MOD;
    }
};