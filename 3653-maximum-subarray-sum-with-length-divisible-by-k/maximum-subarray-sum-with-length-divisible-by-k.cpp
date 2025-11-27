class Solution {
public:
    long long maxSubarraySum(vector<int>& a, int k) {
        int n = a.size();
        std::vector<long long> p(n);
        std::vector<long long> v(n);
        p[0] = a[0];
        for (int i = 1; i < n; i++) {
            p[i] = p[i - 1] + a[i];
        }
        long long ans = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            if (i + 1 - k < 0) {
                v[i] = 0;
            } else if(i+1-k==0){
                v[i] = p[i];
                ans = max(ans, v[i]);
            }else {
                long long x = p[i] - p[i - k];
                v[i] = max(x + v[i - k], x);
                ans = max(ans, v[i]);
            }
            
        }
        return ans;
    }
};