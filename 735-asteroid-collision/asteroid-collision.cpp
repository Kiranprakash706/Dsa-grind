class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n=arr.size();
        // vector<int > ans();
        stack<int>st;
        for(int x:arr){
            if(x>0){
                st.push(x);
            }
            else{
                while(!st.empty() && st.top()>0 && st.top()<abs(x)){
                    st.pop();
                }
                if(!st.empty() && st.top()==abs(x)){
                    st.pop();
                }
                else if(st.empty() || st.top()<0){
                    st.push(x);
                }
            }
        }
        vector<int >ans(st.size());
        for(int i=st.size()-1 ;i>=0;i--){
            ans[i]=st.top();
            st.pop();
        }
        return ans;

    }
};