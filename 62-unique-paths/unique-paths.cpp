class Solution {
public:
int ans=0;
int  helper(int x, int y,int m, int n, vector<vector<int >>&dp){
    if(x==m-1 &&y==n-1){
        return dp[x][y]=1;
       
    }
    if(x<0 || y<0 || x>=m || y>=n){
        return 0;
    }
    if(dp[x][y]!=-1){
        return dp[x][y];
    }
    int a=helper(x+1, y, m, n,dp);
    int b=helper(x, y+1,m, n, dp);

    return dp[x][y]=a+b;
}
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        helper(0, 0, m, n, dp);
        return dp[0][0];
    }
};