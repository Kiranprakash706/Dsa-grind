class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int>ans;
    ans.push_back(asteroids[0]);
    bool isalive=false;
    for(int i=1;i<asteroids.size();i++){
        isalive=true;
        while(isalive && !ans.empty() && asteroids[i]<0 && ans.back()>0){
            if(abs(ans.back())==abs(asteroids[i])){
                ans.pop_back();
                isalive=false;
            }
            else if((abs(ans.back())>abs(asteroids[i]) )){
    
                isalive=false;

            }
            else{
                ans.pop_back();
                isalive=true;
            }
            
        }
        if(isalive){
            ans.push_back(asteroids[i]);
        }
    }
    return ans;
    }
};