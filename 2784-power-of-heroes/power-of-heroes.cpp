/*class Solution {
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
};*/

class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long tobe=0,cur=0;
        long long sum=0, mod=1e9+7;
        for(auto i: nums){
            long long val = 1LL*i*i%mod;
            cur=tobe;
            tobe*=2;
            tobe%=mod;
            tobe+=i;
            cur%=mod;
            sum+=(val*cur%mod + val*i%mod)%mod;
            sum%=mod;
        }
        return sum;

    }
};