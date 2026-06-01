class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int opta=nums[nums.size()-2]-nums[1];
        int optb=nums[nums.size()-1]-nums[2];
        int optc=nums[nums.size()-3]-nums[0];
        return min(opta,min(optb, optc));
    }
};