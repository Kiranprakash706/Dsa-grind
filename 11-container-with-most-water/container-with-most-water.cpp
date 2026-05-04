class Solution {
public:
    int maxArea(vector<int>& height) {
        long long  area=0;
        int i=0;
        int j=height.size()-1;
        while(i<j){
            long long sum=min(height[i], height[j])*(j-i);
            area=max(area, sum);
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return area;
      
    }
};