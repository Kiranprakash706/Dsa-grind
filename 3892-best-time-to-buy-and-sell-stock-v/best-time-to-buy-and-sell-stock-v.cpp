class Solution {
public:
    vector<vector<vector<vector<long long>>>> dp;
    vector<int> prices;
    int n, K;
    long long solve(int idx, int done, int type, int running) {
        if (idx == n)
            return running ? LLONG_MIN : 0;
        long long &res = dp[idx][done][type][running];
        if (res != LLONG_MIN) return res;
        res = solve(idx + 1, done, type, running);
        long long price = prices[idx];
        if (!running && done < K) {
            long long nxt;
            nxt = solve(idx + 1, done, 0, 1);
            if (nxt != LLONG_MIN)
                res = max(res, nxt - price);
            nxt = solve(idx + 1, done, 1, 1);
            if (nxt != LLONG_MIN)
                res = max(res, nxt + price);
        }
        if (running && done < K) {
            long long nxt;

            if (type == 0) { 
                nxt = solve(idx + 1, done + 1, 0, 0);
                if (nxt != LLONG_MIN)
                    res = max(res, nxt + price);
            }
            if (type == 1) { 
                nxt = solve(idx + 1, done + 1, 1, 0);
                if (nxt != LLONG_MIN)
                    res = max(res, nxt - price);
            }
        }
        return res;
    }
    long long maximumProfit(vector<int>& p, int k) {
        prices = p;
        n = prices.size();
        K = k;
        dp.assign(n + 1,
            vector<vector<vector<long long>>>(
                K + 1,
                vector<vector<long long>>(2, vector<long long>(2, LLONG_MIN))
            )
        );

        return solve(0, 0, 0, 0);
    }
};