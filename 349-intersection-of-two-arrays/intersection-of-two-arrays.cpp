class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {


        unordered_map<int,bool>mapp;
        for(int i=0;i<nums1.size();i++){
            mapp[nums1[i]]=true;
        }
        unordered_set<int>st;
  
        for(int i=0;i<nums2.size();i++){
            if(mapp.find(nums2[i])!=mapp.end()){
                st.insert(nums2[i]);
            }
        }
       vector<int>result(st.begin(), st.end());
        return result;
    }
};