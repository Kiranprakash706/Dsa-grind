class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int sum=accumulate(nums.begin(), nums.end(), 0);
        int n=nums.size()-1;
        vector<int>ans;
        int temp=0;

        for(int i=0;i<nums.size();i++){
           if(i==0){
            int tempo=sum-nums[i];
            ans.push_back(abs(tempo-n*nums[0]));
           }
           else{
            int left=i-0;
            int right=n-i;
            int tempo=sum-nums[i];
            int leftans=abs(temp-left*nums[i]);
            int rightans=abs(nums[i]*right-tempo);
            ans.push_back(leftans+rightans);
           }
            temp+=nums[i];
            sum-=nums[i];
        }
        return ans;
    }
};