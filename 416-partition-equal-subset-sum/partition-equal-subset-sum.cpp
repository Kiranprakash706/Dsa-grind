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
        
        vector<vector<int>>dp(n, vector<int>(m + 1, 0));
        // bool ans= helper(nums, n-1,m,dp);
        // return dp[n-1][m];

        for(int i=0;i<n;i++){
            dp[i][0]=1;

        }
        if(nums[0]<=m){
            dp[0][nums[0]]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=m;j++){
                bool a=false;
                if(nums[i]<=j){
                    a=dp[i-1][j-nums[i]];
                }
                bool b=dp[i-1][j];
                dp[i][j]=a||b;

            }
        }
        return dp[n-1][m];


       
    }
};