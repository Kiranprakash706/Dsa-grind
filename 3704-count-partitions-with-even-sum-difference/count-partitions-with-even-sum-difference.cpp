class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int size = nums.size();

        // Step 1: Calculate total sum
        long long total = 0;
        for (int x : nums) total += x;

        long long left = 0;
        int count = 0;

        // Step 2: Check all possible partitions
        for (int i = 0; i < size - 1; i++) {
            left += nums[i];                // Left part ka sum
            long long right = total - left; // Right part ka sum

            long long diff = left - right;  // Difference

            if (abs(diff) % 2 == 0) {       // Even check
                count++;
            }
        }

        return count;
    }
};