/*class Solution {
public:
    const long long MOD = 1e9 + 7;
    long long mx = LLONG_MAX;
int helper(int ind, vector<int>&coins , int sum, vector<vector<long long >>&dp){
      if(sum==0){
          return 1;
      }
      if(ind==0){
          if(sum%coins[0]==0){
              return 1;
          }
          else{
              return 0;
          }
      }
      if(dp[ind][sum]!=-1){
          return dp[ind][sum];
      }
      else{
          long long  pick=0;
          if(sum>=coins[ind]){
              pick=helper(ind, coins , sum-coins[ind],dp);
          }
          long long  notpick=helper(ind-1, coins, sum, dp);
          return dp[ind][sum]=pick+notpick;
      }
  }
    int change(int sum, vector<int>& coins) {
        int n=coins.size();
      vector<vector<long long >>dp(n, vector<long long >(sum+1, 0));
        // return helper(n-1, coins, sum, dp);
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        for(int i=0;i<=sum;i++){
            if(i%coins[0]==0){
                dp[0][i]=1;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                long long  pick=0;
                if(j>=coins[i]){
                    pick=dp[i][j-coins[i]];
                }
                long long  notpick=dp[i-1][j];
               if(pick+notpick>=mx){
                 dp[i][j]=(pick+notpick)%MOD;
               }
               else{
                    dp[i][j]=(pick+notpick);
               }
               
                
            }
        }
        return dp[n-1][sum];
        
    }
};
*/



// corrected code by akshit sharma 


class Solution {
public:

    int change(int sum, vector<int>& coins) {
        int n=coins.size();
      vector<vector<long long >>dp(n, vector<long long >(sum+1, 0));
      
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<=sum;j++){
                long long  pick=0;
                if(j>=coins[i]){
                    pick=dp[i][j-coins[i]];
                }
                long long  notpick=0;
                if(i!=0)notpick=dp[i-1][j];
                long long cur=LLONG_MAX;
                cur-=pick;
                if(cur-notpick>=0)dp[i][j]=(pick+notpick);
            }
        }
        return dp[n-1][sum];
        
    }
};