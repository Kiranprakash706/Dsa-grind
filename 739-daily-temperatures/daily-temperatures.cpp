class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        vector<int>ans(arr.size(),0);
        int n=arr.size();
        stack<int>st;
        for(int  i=0;i<arr.size();i++){
            if(!st.empty() && arr[i]>arr[st.top()]){
                while(!st.empty() && arr[i]>arr[st.top()]){
                    int prev=st.top();
                    ans[prev]=i-st.top();
                    st.pop();
                }
            }
            st.push(i);
        }
        return ans;
    }
};



