class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int len=0;
        int maxlen=0;
        int l=0;
        int r=0;
        int zero=0;
       while(r<nums.size()){
        if(nums[r]==1){
            r++;
            len++;
              maxlen=max(maxlen,len);
        }
        else if( nums[r]==0 && zero<k){
            r++;
            len++;
            zero++;
              maxlen=max(maxlen,len);
        }
        else if(nums[r]==0 && zero>=k){
            while(zero>=k){
                if(nums[l]==0){
                    zero--;
                }
                l++;
                len--;
            }
        }
      
       }
       return maxlen;
    }
};