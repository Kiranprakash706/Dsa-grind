class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> rowPrefixSum(n,vector<int>(m));    
        vector<vector<int>> colPrefixSum(n,vector<int>(m));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                rowPrefixSum[i][j] = (j?rowPrefixSum[i][j-1] : 0) + grid[i][j];
                colPrefixSum[i][j] = (i?colPrefixSum[i-1][j] : 0) + grid[i][j];
            }
        }    
        auto isok = [&](int len)
        {
            for(int i = len-1; i < n; i++)
            {
                for(int j = len-1; j < m; j++)
                {
                    int ti = i-len+1;
                    int tj = j-len+1;
                    int di = ti;
                    int dj = tj;
                    int xi = ti;
                    int xj = j;
                    int sum = 0;
                    int d1 = 0;
                    int d2 = 0;
                    int v = len;
                    int rowItr = ti;
                    int colItr = tj;
                    while(v--)
                    {
                        int currSum = rowPrefixSum[rowItr][j]-(tj?rowPrefixSum[rowItr][tj-1]:0);
                        if(sum && currSum != sum)
                        {
                            sum = -1;
                            break;
                        }
                        currSum = colPrefixSum[i][colItr] - (ti?colPrefixSum[ti-1][colItr]:0);
                        if(sum && currSum != sum)
                        {
                            sum = -1;
                            break;
                        }
                        sum = currSum;
                        rowItr++;
                        colItr++;
                        d1 += grid[di++][dj++];
                        d2 += grid[xi++][xj--];
                    }
                    if(d1 == d2 && d2 == sum) return 1;
                }
            }
            return 0;
        };

        for(int len = min(n,m); len >= 1; len--)
        {
            if(isok(len))
            {
                return len;
            }
        }
        return 0;
    }
};