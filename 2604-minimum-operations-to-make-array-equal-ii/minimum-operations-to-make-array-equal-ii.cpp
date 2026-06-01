class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long posdiff=0;
        long long negdiff=0;
        if(k==0){
            if(nums1==nums2){
                return 0;
            }
            else{
                return -1;
            }
        }
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]-nums2[i]>0){
                if((nums1[i]-nums2[i])%k==0){
                     posdiff+=nums1[i]-nums2[i];
                }
                else{
                        return -1;
                }

            }
            else if(nums1[i]==nums2[i]){
                continue;
            }
            else{
                if((nums2[i]-nums1[i])%k==0){
                    negdiff+=nums2[i]-nums1[i];
                }
                else{
                    return -1;
                }
            }
        }
        if(posdiff==negdiff){
            return posdiff/k;
        }
        return -1;
    }
};