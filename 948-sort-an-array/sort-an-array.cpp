class Solution {
public:
void heapify(vector<int>&nums, int curr_size_of_heap, int ind_to_heapify){
    int largest=ind_to_heapify;
    int left=2*ind_to_heapify+1;
    int right=2*ind_to_heapify+2;
    if(left<curr_size_of_heap && nums[largest]<nums[left]){
        largest=left;
    }
    if(right<curr_size_of_heap && nums[largest]<nums[right]){
        largest=right;

    }
    if(largest!=ind_to_heapify){
        swap(nums[largest], nums[ind_to_heapify]);
        heapify(nums,curr_size_of_heap,largest);
        
    }
}
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=n/2;i>=0;i--){
            heapify(nums,n,i);
        }
        for(int i=n-1;i>=0;i--){
            swap(nums[0], nums[i]);
            heapify(nums,i,0);
        }
        return nums;
    }
};