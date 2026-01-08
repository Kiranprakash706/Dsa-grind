class Solution {
    int findDotProduct(vector<int>& nums1, vector<int>& nums2, int i, int j, int empty,
                        vector<vector<vector<int>>>&dp) {
        if(i == 0) {
            int maxProd = nums1[0]*nums2[j--];
            while(j>=0) {
                maxProd = max(maxProd, nums1[0]*nums2[j--]);
            }

            if(empty) return maxProd;
            return max(0, maxProd);
        }
        if(j == 0) {
            int maxProd = nums1[i--]*nums2[0];
            while(i>=0) {
                maxProd = max(maxProd, nums1[i--]*nums2[0]);
            }

            if(empty) return maxProd;
            return max(0, maxProd);
        }

        if(dp[i][j][empty] != -1e9) return dp[i][j][empty];
        int take = findDotProduct(nums1, nums2, i-1, j-1, 0, dp) + nums1[i]*nums2[j];

        int notTake = max(findDotProduct(nums1, nums2, i, j-1, empty, dp),
                        findDotProduct(nums1, nums2, i-1, j, empty, dp));

        return dp[i][j][empty] = max(take, notTake);
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(2, -1e9)));

        return findDotProduct(nums1, nums2, n-1, m-1, 1, dp);
    }
};