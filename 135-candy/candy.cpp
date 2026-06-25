class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int>left(ratings.size(),1),right(ratings.size(),1);
        for(int i=0;i<ratings.size();i++){
            if(i==0){
                continue;
            }
            else{
            if(ratings[i]>ratings[i-1]){
                left[i]=left[i-1]+1;
            }
            }
        }
        for(int i=ratings.size()-1;i>=0;i--){
            if(i==ratings.size()-1){
                continue;
            }
            else{
            if(ratings[i]>ratings[i+1]){
                right[i]=right[i+1]+1;
            }
            }
        }
        int numberofcandy=0;
        for(int i=0;i<ratings.size();i++){
            numberofcandy+=max(left[i], right[i]);
        }
        return numberofcandy;
    }
};