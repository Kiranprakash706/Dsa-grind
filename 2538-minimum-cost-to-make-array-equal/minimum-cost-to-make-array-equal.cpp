class Solution {
public:
long long helper(int mid, vector<int >&nums, vector<int >&cost){
    long long ans=0;
    for(int i=0;i<nums.size();i++){
        long long temp=(long long)abs(nums[i]-mid)*cost[i];
        ans+=temp;
    }
    return ans;
}
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int lb=*min_element(nums.begin(), nums.end());
        int hb=*max_element(nums.begin(), nums.end());
        
        while(lb<hb){
            int mid=lb+(hb-lb)/2;
            long long c1=helper(mid, nums, cost);
            long long c2=helper(mid+1, nums, cost);
            if(c1<c2){
                hb=mid;
            }
            else{
                lb=mid+1;
            }
        }
        return helper(hb, nums, cost);
    }
};