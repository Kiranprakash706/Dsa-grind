class Solution {
public:
    string decodeString(string s) {
        stack<int>numstack;
        stack<string>strstack;
        int num=0;
        string str="";
        for(char ch:s){
            if(isdigit(ch))
                    {
                 num=num*10+(ch-'0');
            }
            else if(ch=='['){
                numstack.push(num);
                num=0;
                strstack.push(str);
                str="";
            }
            else if(ch==']'){
                int a=numstack.top();
                numstack.pop();
                string temp=strstack.top();
                strstack.pop();
                string curr="";
                for(int i=0;i<a;i++){
                    curr+=str;
                }
                str=temp+curr;
                

            }
            else {
                str=str+ch;
            }  
        }
        return str;
    }
};