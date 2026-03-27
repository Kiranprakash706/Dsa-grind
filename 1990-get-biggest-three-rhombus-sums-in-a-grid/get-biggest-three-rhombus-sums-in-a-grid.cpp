class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        set<int>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                st.insert(grid[i][j]);

                for(int size=1;;size++){
                    int x=i-size;
                    int y=j;

                   if(i - size < 0 || i + size >= n || j - size < 0 || j + size >= m) {
                        break;
                     }
                    int sum=0;
                    for(int t=0;t<size;t++){
                        sum+=grid[x][y];
                        x++;
                        y++;
                    }
                    for(int t=0;t<size;t++){
                        sum+=grid[x][y];
                        x++;
                        y--;
                    }
                    for(int t=0;t<size;t++){
                        sum+=grid[x][y];
                        x--;
                        y--;
                    }
                    for(int t=0;t<size;t++){
                        sum+=grid[x][y];
                        x--;
                        y++;
                    }
                    st.insert(sum);
                }
            }
        }
        vector<int>result;
        for(auto it=st.rbegin();it!=st.rend() && result.size()<3;it++){
            result.push_back(*it);
        }
        return result;
    }
};