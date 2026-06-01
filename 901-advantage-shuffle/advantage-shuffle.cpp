class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans(nums1.size(),0);
        sort(nums1.begin(),nums1.end());
        vector<vector<int>>v;
        for(int i=0;i<nums2.size();i++){
            v.push_back({nums2[i],i});
        }
        sort(v.begin(), v.end());
        int i=nums1.size()-1;
        int j=i;
        int k=0;
        while(k<=i && j<v.size()){
            if(nums1[i]>v[j][0]){
                ans[v[j][1]]=nums1[i];
                i--;
                j--;
            }
            else {
                ans[v[j][1]]=nums1[k];
                k++;
                j--;
            }
        }
        
        return ans;
    }
};