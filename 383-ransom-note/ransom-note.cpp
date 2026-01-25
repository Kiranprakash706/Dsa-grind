class Solution {
public:
    bool canConstruct(string ransomnote, string magazine) {
        unordered_map<char, int > mapp;
        for(int i=0;i< magazine.size();i++){
            mapp[magazine[i]]++;
        }  
        for(int i=0;i<ransomnote.size();i++){
            if(mapp.find(ransomnote[i])!=mapp.end()){
                if(mapp[ransomnote[i]]>1){
                    mapp[ransomnote[i]]--;
                }
                else{
                    mapp.erase(ransomnote[i]);
                }
            }
            else{
                return false;
                break;
            }
        }
        return true;
          }
};
