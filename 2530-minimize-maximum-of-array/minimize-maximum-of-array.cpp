class Solution {
public:
bool ispossible(vector<int>&nums, int mid){
    long long carry=0;
    for(int i=nums.size()-1;i>0;i--){
        if(nums[i]+carry>mid){
            carry+=nums[i]-mid;
        }
        else{
            carry=0;
        }
    }
    return nums[0]+carry<=mid;
}
    int minimizeArrayValue(vector<int>& nums) {
        int lb=0;
        int hb=*max_element(nums.begin(), nums.end());
        int ans=hb;
        while(lb<=hb){
            int mid=hb+(lb-hb)/2;
            if(ispossible(nums, mid)){
                ans=mid;
                hb=mid-1;
            }
            else{
                lb=mid+1;
            }
        }
        return ans;
    }
};