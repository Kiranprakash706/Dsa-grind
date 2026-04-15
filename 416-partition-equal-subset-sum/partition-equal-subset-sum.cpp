class Solution {
public:
bool helper(vector<int>&nums, int ind, int sum, vector<vector<int>>&dp){
    if(sum==0){
        return true;
    }
    if(ind==0){
        if(sum==nums[ind]){
            return true;
        }
        return false;

    }
    if(dp[ind][sum]!=-1){
        return dp[ind][sum];
    }
    else{
        bool a=false;
        if(nums[ind]<=sum){
            a=helper(nums,ind-1,sum-nums[ind],dp);
        }
        bool b=helper(nums, ind-1, sum, dp);
        return dp[ind][sum]=a||b;
    }

}
    bool canPartition(vector<int>& nums) {
        if(nums.size()==1){return false;}
        int n=nums.size();
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if(sum%2!=0){
            return false;

        }
        int m=sum/2;
        
        vector<vector<int>>dp(n, vector<int>(m + 1, -1));
        bool ans= helper(nums, n-1,m,dp);
        return dp[n-1][m];
       
    }
};