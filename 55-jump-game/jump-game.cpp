class Solution {
public:
 vector<int>dp;
int  helper(int ind, vector<int>&nums){
    if(ind==nums.size()-1){
        return true;
    }
    if(nums[ind]==0){
        return false;
    }
    if(dp[ind]!=-1){
        return dp[ind];
    }
    else{
    bool ispossible=false;
    for(int i=1;i<=nums[ind];i++){
        ispossible=helper(ind+i, nums);
        if(ispossible){
            return dp[ind]=1;
        }
    }
    return dp[ind]=0;
    }
}
    bool canJump(vector<int>& nums) {
       dp.resize(nums.size()+1,-1);
        return helper(0, nums);
    }
};