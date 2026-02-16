class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        if(nums.size()<=3){
            return 0;
        }
        sort(nums.begin(), nums.end());
    int n=nums.size()-1;
       int option1=abs(nums[2]-nums[n]);
       int option2=abs(nums[n-2]-nums[0]);
       int option3=abs(nums[n-1]-nums[1]);
       return min(option1, min(option2, option3));
    }
};