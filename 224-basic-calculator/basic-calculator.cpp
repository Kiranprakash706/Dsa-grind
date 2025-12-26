class Solution {
public:
    int calculate(string s) {
       long long  res=0;
       long long  num=0;
       int sign=1;
       stack<long long >st;
       for(char c:s){
        if(isdigit(c)){
            num=num*10+(c-'0');
        }
        else if(c=='+'){
            res+=num*sign;
            sign=1;
            num=0;
        }
        else if(c=='-'){
            res+=num*sign;
            sign=-1;
            num=0;
        }
        else if(c=='('){
            st.push(sign);
            st.push(res);
            res=0;
            num=0;sign=1;
        }
        else if(c==')'){
            res += sign * num;
            num = 0;
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            res=res*b;
            res=res+a;
        }
        else {
            continue;
        }
       } 
       res+=num*sign;
       return res;
    }

};