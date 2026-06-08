class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        /*vector<int>a;
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
        */

        //now doing by single vetor;
        int left=0;
        int right=nums.size()-1;
        vector<int>res(nums.size(),0);
        for(int i=0 , j=nums.size()-1;i<nums.size() && j>=0;i++,j--){
            if(nums[i]<pivot){
                res[left]=nums[i];
                left++;
            }
            if(nums[j]>pivot){
                res[right]=nums[j];
                right--;
            }

        }
        while(left<=right){
            res[left]=res[right]=pivot;
            left++;
            right--;
        }
        return res;
    }
};