class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>temp;

        for(int i:nums){
            auto it=lower_bound(temp.begin(),temp.end(),i);
            if(it==temp.end()){
                temp.push_back(i);
            }
            else{
                int ab=i;
                *it=ab;
            }
        }
        return temp.size();
    }
};


