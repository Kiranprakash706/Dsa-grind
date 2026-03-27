class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<int> st;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                // k = 0 (single cell)
                st.insert(grid[i][j]);

                // try all sizes
                for(int k = 1; ; k++) {
                    if(i - k < 0 || i + k >= m || j - k < 0 || j + k >= n)
                        break;

                    int sum = 0;

                    // 1. top → right (down-right)
                    int x = i - k, y = j;
                    for(int t = 0; t < k; t++) {
                        sum += grid[x][y];
                        x++; y++;
                    }

                    // 2. right → bottom (down-left)
                    for(int t = 0; t < k; t++) {
                        sum += grid[x][y];
                        x++; y--;
                    }

                    // 3. bottom → left (up-left)
                    for(int t = 0; t < k; t++) {
                        sum += grid[x][y];
                        x--; y--;
                    }

                    // 4. left → top (up-right)
                    for(int t = 0; t < k; t++) {
                        sum += grid[x][y];
                        x--; y++;
                    }

                    st.insert(sum);
                }
            }
        }

        vector<int> res;
        for(auto it = st.rbegin(); it != st.rend() && res.size() < 3; ++it) {
            res.push_back(*it);
        }

        return res;
    }
};