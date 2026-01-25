class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int , int> mapp;
        for(int i=0;i<arr.size();i++){
            mapp[arr[i]]++;
        }
        unordered_map<int , bool>mapp2;
        for(auto &i: mapp){
           
            if(mapp2.find(i.second)!=mapp2.end()){
                return false;
                break;
            }
             mapp2[i.second]=true;
            
        }
        return true;
    }
};