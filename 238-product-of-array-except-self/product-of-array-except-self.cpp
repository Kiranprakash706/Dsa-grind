class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>pref(nums.size());
        vector<int>suff(nums.size());
        for(int i=0;i<nums.size();i++){
            if(i==0){
                pref[i]=nums[0];
            }
            else{
                pref[i]=pref[i-1]*nums[i];
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(i==nums.size()-1){
                suff[i]=nums[i];
            }
            else{
                suff[i]=suff[i+1]*nums[i];
            }
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(i==0){
                ans.push_back(suff[i+1]);
            }
            else if(i==nums.size()-1){
                ans.push_back(pref[i-1]);
            }
            else{
                ans.push_back(pref[i-1]*suff[i+1]);
            }


        }
        return ans;
        
    }
};