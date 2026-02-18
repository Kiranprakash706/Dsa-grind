class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long sum = 0;
        int answer = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            // The minimum possible max at this point is the ceiling of the prefix average
            answer = max(answer, (int)((sum + i) / (i + 1)));
        }
        return answer;
    }
};