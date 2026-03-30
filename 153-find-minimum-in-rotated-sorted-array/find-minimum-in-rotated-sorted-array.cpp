class Solution {
public:
    int findMin(vector<int>& nums) {
      int lb=0;
      int ans=INT_MAX;
      int hb=nums.size()-1;
        while(lb<=hb){
            int mid=lb+(hb-lb)/2;
            // if(nums[lb]<=nums[hb]){
            //     ans=min(ans,nums[lb]);
            // }  
            if(nums[lb]<=nums[mid] && nums[hb]<=nums[mid]){
                ans=min(ans,nums[hb]);
                lb=mid+1;
            }
            else{
                ans=min(ans, nums[mid]);
                hb=mid-1;
            }
        }
        return ans;
           
    }
};