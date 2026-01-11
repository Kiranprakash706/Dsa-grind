class Solution {
public:
    vector<int> nextsmaller(int* height, int n){
        stack<int>s;
        s.push(-1);
        vector<int>ans(n);
        for(int i=n-1; i>=0;i--){
            int curr=height[i];
        while(s.top()!=-1&& height[s.top()]>=curr){
            s.pop();

        }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> prevsmaller(int* height, int n){
        stack<int>s;
        s.push(-1);
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int curr=height[i];
            while(s.top()!=-1&& height[s.top()]>=curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    int largestarearectangle(int* height, int n){
        vector<int> next=nextsmaller(height, n);
        vector<int> prev=prevsmaller(height, n);

        int area=INT_MIN;
        for(int i=0;i<n;i++){
            int l=height[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int b=next[i]-prev[i]-1;
            int newarea=l*b;
            area=max(area,newarea);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
         if (matrix.empty()) return 0; 
        
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>height(m,0);

        int area=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    height[j]++;
                }
                else{
                    height[j]=0;
                }
                
            }
            area=max(area,largestarearectangle(&height[0],m));
        }
        
        return area;

    }
};