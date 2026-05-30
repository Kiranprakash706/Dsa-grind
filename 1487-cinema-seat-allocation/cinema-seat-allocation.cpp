class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_set<int>>mapp;
        for(int i=0;i<reservedSeats.size();i++){
            mapp[reservedSeats[i][0]].insert(reservedSeats[i][1]);
        }
        int res=2*(n-mapp.size());
        for(auto &i:mapp){
            bool left=true;
            bool right =true;
            bool middle =true;
            for(int j=2;j<=5;j++){
                if(i.second.count(j)){
                    left=false;
                    break;
                }

            }
            for(int j=6;j<=9;j++){
                if(i.second.count(j)){
                    right=false;
                    break;
                }
            }
            for(int j=4;j<=7;j++){
                if(i.second.count(j)){
                    middle=false;
                    break;
                }
            }
            if(left&& right){
                res+=2;
            }
            else if(left|| right|| middle ){
                res+=1;
            }
        }
        return res;
    }
};