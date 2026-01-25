class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxlen=0;
        int sum=0;
        unordered_map<int , int > mapp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                sum+=-1;
            }
            else{
                sum+=nums[i];
            }

            if(sum==0){
                maxlen=i+1;
            }
            if(mapp.find(sum)!=mapp.end()){
                maxlen=max(maxlen, i-mapp[sum]);
            }
            else{
                mapp[sum]=i;
            }
        }
        return maxlen;
    }
};