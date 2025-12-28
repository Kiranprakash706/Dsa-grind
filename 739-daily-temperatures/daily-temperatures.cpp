class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        stack<int>st;
        vector<int>ans(arr.size(), 0);
        for(int i=0;i<arr.size();i++){
            if(!st.empty() && arr[st.top()]<arr[i]){
                while(!st.empty()&& arr[st.top()]<arr[i]){
                    int prev=st.top();
                    ans[prev]=i-prev;
                    st.pop();
                }
            }
            st.push(i);
    
    }
    return ans;
    }

};