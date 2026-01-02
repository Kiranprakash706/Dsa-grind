class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size()/2;
        int ans = 0;

        unordered_map<int, int> m;

        for (int i:nums){
            m[i]++;
        }

        for (auto& pair:m){
            if (pair.second == n){
                ans = pair.first;
            }
        }

        return ans;
        
    }
};