class Solution {
public:
    string makeSmallestPalindrome(string s) {
       int i=0;
       int opt=0;
       int j=s.length()-1;
       while(i<=j){
        if(s[i]!=s[j]){
            opt++;
            int a=(int)s[i];
            int b=(int)s[j];
            int temp=min(a,b);
            s[i]=s[j]=(char)temp;
            
        }
        i++;
        j--;

       } 
       return s;
    }
};