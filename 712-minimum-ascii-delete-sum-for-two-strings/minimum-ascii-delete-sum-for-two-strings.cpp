class Solution {

  private:

    string s1_;
    string s2_;
    vector<vector<int>> memo;

    int dp(int i, int j) {
      if (i == -1 || j == -1) {
        return 0;
      }

      if (memo[i][j] != -1)
        return memo[i][j];
      
      if (s1_[i] == s2_[j]) {
        return memo[i][j] = dp(i - 1, j - 1) + s1_[i] ;
      }

      return memo[i][j] = max(
        dp(i, j - 1),
        dp(i - 1, j)
      );

    }

  public:
    int minimumDeleteSum(string s1, string s2) {
      s1_ = s1;
      s2_ = s2;
      int n = s1_.size();
      int m = s2_.size();
      int t = 0;

      memo.assign(n, vector<int>(m, -1));

      for (int i = 0; i < n; i++)
        t += s1_[i];

      for (int j = 0; j < m; j++)
        t += s2_[j]; 

      return t - (2 * dp(n - 1, m - 1) );
    }
};