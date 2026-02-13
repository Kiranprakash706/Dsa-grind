class Solution {
public:
int findatmostk(vector<int >nums, int k){
    int ans=0;
        int r=0;
        int l=0;
        unordered_map<int , int > mapp;
        while(r<nums.size()){
            mapp[nums[r]]++;
            while(mapp.size()>k){
                mapp[nums[l]]--;
                if(mapp[nums[l]]==0){
                    mapp.erase(nums[l]);

                }
                l++;

            }
           
                ans+=(r-l+1);
            
           
            r++;
        }
        return ans;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return findatmostk(nums, k)-findatmostk(nums, k-1);
    }
};