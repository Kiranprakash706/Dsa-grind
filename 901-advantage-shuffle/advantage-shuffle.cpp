class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        vector<pair<int, int>>v;
        for(int i=0;i<nums2.size();i++){
            v.push_back({nums2[i], i});
        }
        sort(v.begin(), v.end());
        int i=nums1.size()-1;
        int j=v.size()-1;
        vector<int > res(nums1.size(),-1);
        int lef=0;
        while(i>=0 && j>=0){
           if(nums1[i]>v[j].first){
                res[v[j].second]=nums1[i];
                i--;
                j--;
           }
           else {
            res[v[j].second]=nums1[lef];
            lef++;
            j--;
           }
            
        }
        return res;
    }
};