class Solution {
public:
int helper(int ind, vector<int>&coins,int amount, vector<vector<int>>&dp){
    if(amount==0){
        return 0;
    }
    if(ind==0){
       if(amount%coins[0]==0){
        return amount/coins[0];
       }
       return INT_MAX;
    }
    if(dp[ind][amount]!=-1){
        return dp[ind][amount];
    }
    else{
        int pick=INT_MAX;
        if(coins[ind]<=amount){

            int res=helper(ind, coins, amount-coins[ind], dp);
            if(res!=INT_MAX){
                pick=1+res;
            }
        }
        int notpick=helper(ind -1, coins, amount, dp);
        return dp[ind][amount]=min(pick, notpick);
    }
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));

        int ans = helper(n-1, coins, amount, dp);
        return (ans==INT_MAX)?-1:ans;

    }
};