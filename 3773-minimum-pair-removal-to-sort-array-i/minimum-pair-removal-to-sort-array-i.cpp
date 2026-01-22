class Solution {
public:
    bool isSorted(vector<int>& nums){
        for (int i = 0; i<nums.size()-1 ; i++){
            if (nums[i]>nums[i+1]) return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        //we will do brute force
        int operations = 0;
        int min_sum;
        int min_sum_index;
        while (!isSorted(nums)){
            operations++;
            min_sum = INT_MAX;
            for (int i = 0; i<nums.size()-1 ; i++){
                if (nums[i]+nums[i+1]<min_sum){
                    min_sum = nums[i] + nums[i+1];
                    min_sum_index = i;
                }
            }
            vector<int> nums2;
            for (int i = 0; i<nums.size() ; i++){
                if (i==min_sum_index) nums2.push_back(min_sum);
                else if (i==min_sum_index+1) continue;
                else nums2.push_back(nums[i]);
            }
            nums = nums2;
        }
        return operations;
    }
};