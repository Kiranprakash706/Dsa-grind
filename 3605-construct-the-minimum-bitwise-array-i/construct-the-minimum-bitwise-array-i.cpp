class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (auto &i : nums) {
            bool b = true;
            for (int j = 1; j < i; j++) {
                if ((j | (j + 1)) == i) {
                    ans.push_back(j);
                    b = false;
                    break;
                }
            }
            if (b) ans.push_back(-1);
        }
        return ans;
    }
};