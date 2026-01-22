class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0;
        int res=0;
        unordered_map<int , int > mapp;
        // mapp[0]=1;
        for(int i=0;i<nums.size();i++){
            
           sum+=nums[i];
           if(sum%k==0){
                res++;
            }
           int temp=(sum%k+k)%k;
           if(mapp.find(temp)!=mapp.end()){
            res+=mapp[temp];
            mapp[temp]++;
           }
           else{
            mapp[temp]=1;
           }
        }
        return res;
    }
};