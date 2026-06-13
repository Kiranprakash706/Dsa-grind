class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;
        int two=0;
        // sort(bills.begin(), bills.end());
        for(int i=0;i<bills.size();i++){
            if(bills[0]!=5){
                return false;
            }
           
           if(bills[i]==5){
            five++;
           }
           else if(bills[i]==10 && five>0){
            five--;
            ten++;
           }
           else if(bills[i]==20 &&(five>0 || ten>0)){
           if(ten && five){
            ten--;
            five--;
            two++;
           }
           else if(!ten && five>=3){
            five-=3;
            two++;
                       }
           else {
            return false;
           }

           }
           else{
            return false;
           }
        }
        return true;
    }
};