class Solution {
public:
void findprev(vector<int>& prevSmaller, vector<int>& heights) {
    stack<int> st;
    int n = heights.size();
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
        prevSmaller[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
}
void findnext(vector<int>& nextSmaller, vector<int>& heights) {
    stack<int> st;
    int n = heights.size();
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
        nextSmaller[i] = st.empty() ? n : st.top();
        st.push(i);
    }
}
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()==0){
            return 0;
        }
        vector<int>prevsmaller(heights.size());
        vector<int>nextsmaller(heights.size());
        findnext(nextsmaller, heights);
        findprev(prevsmaller, heights);
        int area=0;
        for(int i=0;i<heights.size();i++){
            if(nextsmaller[i]==-1){
                nextsmaller[i]=heights.size();
            }
            int l=heights[i];
            int b=nextsmaller[i]-prevsmaller[i]-1;
            int ans=l*b;
            area=max(area, ans);
                    }

                    return area;
    }
};