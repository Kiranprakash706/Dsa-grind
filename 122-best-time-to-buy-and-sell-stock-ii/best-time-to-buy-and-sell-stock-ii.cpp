class Solution {
public:
int func(vector<int>&prices, int buy,vector<vector<long long >>&dp, int ind, int siz){
    if(ind==siz){
        return 0;
    }
    if(dp[ind][buy]!=-1){
        return dp[ind][buy];
    }
    long long profit=0;
    if(buy){
        profit=max((-prices[ind]+func(prices, 0,dp, ind+1,siz)),0+func(prices, 1,dp,ind+1,siz) );
    }
    else{
        profit=max((prices[ind]+func(prices,1,dp,ind+1,siz)), 0+func(prices,0,dp, ind+1,siz));
    }
    return dp[ind][buy]=profit;
}
    int maxProfit(vector<int>& prices) {
        int  n=prices.size();
        vector<vector<long long >>dp(prices.size()+1,vector<long long >(2,-1));
        return func(prices,1,dp,0,n);
    }
};