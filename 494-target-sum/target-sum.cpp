class Solution {
public:
    int helper(int ind , vector<int>&nums, vector<vector<int>>&dp, int tar){
        if(ind==0){
            if(tar==0 && nums[ind]==0){
                return 2;
            }
            else if(tar==0 || nums[ind]==tar){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[ind][tar]!=-1){
            return dp[ind][tar];
        }
        else{
            int pick=0;
            if(nums[ind]<=tar){
                pick=helper(ind-1, nums, dp, tar-nums[ind]);
            }
            int notpick=helper(ind-1, nums, dp, tar);
            return dp[ind][tar]=pick+notpick;
        }

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n=nums.size();
       
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if(abs(target) > sum){
            return 0;
        }
        if((sum+target)%2!=0){
            return 0;
        }
        int tar=(sum+target)/2;
        vector<vector<int>>dp(n, vector<int>(tar+1,0));
        // return helper(n-1, nums, dp, tar);

        //TABULATION 

            if(nums[0]==0){
                dp[0][0]=2;

            }
            else{
                dp[0][0]=1;
            }

            if(nums[0]!=0 && nums[0]<=tar){
                dp[0][nums[0]]=1;
            }

            for(int i=1;i<n;i++){
                for(int j=0;j<=tar;j++){
                    int pick=0;
                    int notpick=dp[i-1][j];
                    if(j>=nums[i]){
                        pick=dp[i-1][j-nums[i]];

                    }
                    dp[i][j]=pick+notpick;
                }

            }
            return dp[n-1][tar];

    }
};