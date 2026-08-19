class Solution {
public:
int helper(vector<int>&v, vector<int>&dp,int index){
    if(index<0){
        return 0;
    }
    
    if(dp[index]!=-1){
        return dp[index];
    }
    else{
        int a=v[index]+helper(v, dp, index-2);
        int b=0+helper(v,dp,index-1);
        return dp[index]=max(a,b);
    }
}

    int deleteAndEarn(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int c=*max_element(nums.begin(), nums.end());

        vector<int>v(c+1, 0);
       for(int i:nums){
        v[i]+=i;
       }
        
        vector<int>dp(v.size(), -1);
        // return helper(v, dp, v.size()-1);
        dp[0]=v[0];
        dp[1]=max(v[0], v[1]);

        for(int i=2;i<v.size();i++){
            int take=0;
            
            take=v[i]+dp[i-2];
            int nottake=0+dp[i-1];
            dp[i]=max(take, nottake);
        }
        return dp[c];
    }
};