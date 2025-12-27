class Solution {
public:
    int calculate(string s) {
        int num=0;
        char ch='+';
        stack<int >st;
        for(int i=0;i<s.size();i++){
            int c=s[i];
            if(isdigit(c)){
                num=num*10+(c-'0');
            }
            if((!isdigit(c) && !isspace(c) )|| i==s.size()-1){
                if(ch=='+'){
                    st.push(num);
                }
                else if(ch=='-'){
                    st.push(-num);
                }
                else if(ch=='*'){
                    int temp=st.top();
                    st.pop();
                    temp=temp*num;
                    st.push(temp);
                }
                else if(ch=='/'){
                    int temp=st.top();
                    temp=temp/num;
                    st.pop();
                    st.push(temp);
                }
                ch=c;
                num=0;
            }
        }
        int res=0;
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        return res;
    }
};