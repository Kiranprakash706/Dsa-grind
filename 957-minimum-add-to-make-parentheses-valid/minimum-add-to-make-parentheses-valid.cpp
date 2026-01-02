class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int cnt=0;
        int a =0;
       

        for(int i=0;i<s.size();i++){
          if(s[i]=='('){
            a++;
          }
          else if(s[i]==')' && a>0){
            a--;
          }
          else{
            cnt++;
          }
        }
        return cnt+=a;
    }
    //tc O(N);
    //sc O(N);
};



