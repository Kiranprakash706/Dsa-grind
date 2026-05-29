class Solution {
public:

int helper(int temp){
   string tempo=to_string(temp);
   int ans=0;
   for(int i=0;i<tempo.length();i++){
    ans+=(tempo[i]-'0');
   }
   return ans;
}

    int minElement(vector<int>& nums) {
        int val=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int ans=helper(nums[i]);
            val=min(val, ans);
        }
        return val;
    }
};