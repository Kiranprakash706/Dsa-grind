class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans(nums.size());
        for(int i=0;i<nums.size();i++){
            if(i==0){
                ans[i]=nums[i];
            }
            else{
                ans[i]=nums[i]*ans[i-1];
            }
        }
        int temp=ans[nums.size()-2];
        for(int i=nums.size()-1;i>=0;i--){
            if(i==nums.size()-1){
                ans[i]=temp;
                temp=nums[i];
            }
            else if(i==0){
                ans[i]=temp;
            }
            else{
                ans[i]=ans[i-1]*temp;
                temp=temp*nums[i];
            }
        }
        return ans;

    }
};