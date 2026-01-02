class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else{
                if(!st.empty() &&st.top()!='('){
                    cnt++;

                }
                else if(st.empty()){
                    st.push(s[i]);
                }
                else{
                    
                    st.pop();
                }
            }
        }
        cnt+=st.size();
        return cnt;
    }
};



