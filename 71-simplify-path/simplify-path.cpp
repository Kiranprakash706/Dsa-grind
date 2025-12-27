class Solution {
public:
    string simplifyPath(string path) {
        int i=0;
        int n=path.size();
        stack<string>st;
        while(i<n){
            while(path[i]=='/'){
                i++;
            }
            if(i>=n){
                break;
            }
            int start=i;
            string temp;
            while(i<n && path[i]!='/'){
                temp=path.substr(start,i-start+1); 
                i++;
            }
            if(temp=="."){
                temp="";
            }
            else if(temp=="..."){
                st.push(temp);
            }
            else if(temp==".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(temp);
            }

        }
        string res;
        if(st.empty()){
            return "/";
        }
        while(!st.empty()){
            string temp=st.top();
            st.pop();
            res=temp+res;
              res='/'+res;

        }


        return res;
    }
};