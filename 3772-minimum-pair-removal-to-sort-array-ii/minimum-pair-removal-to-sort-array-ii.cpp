class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        vector<long long> llnums(n);
        int decreasing = 0;
        int removals = 0;
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
        set<int> indices;
        indices.insert(0);
        llnums[0] = nums[0];
        for (int i = 1; i < n; i++) {
            llnums[i] = nums[i];
            if (llnums[i - 1] > llnums[i]) {
                decreasing++;
            }
            pq.emplace(llnums[i - 1] + llnums[i], i - 1, i);
            indices.insert(i);
        }
        while (!pq.empty() && decreasing > 0) {
            auto [sum, i, j] = pq.top();
            pq.pop();
            if (indices.contains(i) && indices.contains(j) && llnums[i] + llnums[j] == sum) {
                removals++;
                indices.erase(j);
                if (llnums[i] > llnums[j]) {
                    decreasing--;
                }
                auto it = indices.find(i);
                if (it != indices.begin()) {
                    int prev_index = *prev(it);
                    pq.emplace(llnums[prev_index] + sum, prev_index, i);
                    if (llnums[prev_index] > sum) {
                        decreasing++;
                    }
                    if (llnums[prev_index] > llnums[i]) {
                        decreasing--;
                    }
                }
                if (next(it) != indices.end()) {
                    int next_index = *next(it);
                    pq.emplace(sum + llnums[next_index], i, next_index);
                    if (sum > llnums[next_index]) {
                        decreasing++;
                    }
                    if (llnums[j] > llnums[next_index]) {
                        decreasing--;
                    }
                }
                llnums[i] = sum;
            }
        }
        return removals;
    }
};