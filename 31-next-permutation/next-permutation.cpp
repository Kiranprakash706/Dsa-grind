class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind=-1;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]>nums[i-1]){//3>2
                ind=i-1;
                break;
            }
        }
        if(ind==-1){
            reverse(nums.begin(), nums.end());

        }
        else{
            sort(nums.begin()+ind+1, nums.end());
            for(int i=ind+1;i<nums.size();i++){
                if(nums[i]>nums[ind]){
                    swap(nums[i], nums[ind]);
                    break;
                }
            }
            // sort(nums.begin()+ind+1, nums.end());
            
        }
    }
};