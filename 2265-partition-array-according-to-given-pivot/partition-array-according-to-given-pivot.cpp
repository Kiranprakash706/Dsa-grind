class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>a;
        vector<int >b;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                a.push_back(nums[i]);
            }
            else if(nums[i]>pivot){
                b.push_back(nums[i]);
            }
            else{
                cnt++;
            }
        }
        for(int i=0;i<a.size();i++){
            nums[i]=a[i];
        }
        for(int i=0;i<cnt;i++){
            nums[a.size()+i]=pivot;
        }
        for(int i=0;i<b.size();i++){
            nums[i+cnt+a.size()]=b[i];
        }
        return nums;
    }
};