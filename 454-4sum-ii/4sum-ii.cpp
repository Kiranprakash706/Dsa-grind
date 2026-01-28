class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int , int >mapp;
        for(int a:nums1){
            for(int b:nums2){
                mapp[a+b]++;
            }
        }
        int res=0;
        for(int c:nums3){
            for(int d:nums4){
                if(mapp.find(-(c+d))!=mapp.end()){
                    res+=mapp[-(c+d)];
                }
            }
        }
        return res;
    }
};