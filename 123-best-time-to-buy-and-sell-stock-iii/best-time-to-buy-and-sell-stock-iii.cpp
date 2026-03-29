class Solution {
public:
int func(vector<int>&prices, int buy,vector<vector<vector<int>>>&dp, int ind, int siz, int cap){
    if(ind==siz|| cap==0){
        return 0;
    }
    if(dp[ind][buy][cap]!=-1){
        return dp[ind][buy][cap];
    }
    long long profit=0;
    if(buy){
        profit=max((-prices[ind]+func(prices, 0,dp, ind+1,siz,cap)),0+func(prices, 1,dp,ind+1,siz,cap) );
    }
    else{
        profit=max((prices[ind]+func(prices,1,dp,ind+1,siz,cap-1)), 0+func(prices,0,dp, ind+1,siz,cap));
    }
    return dp[ind][buy][cap]=profit;
}

    int maxProfit(vector<int>& prices) {
        int  n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return func(prices,1,dp,0,n,2);
    }
};