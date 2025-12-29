class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
        for (int a : asteroids) {
            bool alive = true;
            while (alive && !stack.empty() && stack.back() > 0 && a < 0) {
                if (abs(stack.back()) < abs(a)) {
                    stack.pop_back();
                } else if (abs(stack.back()) == abs(a)) {
                    stack.pop_back();
                    alive = false;
                } else {
                    alive = false;
                }
            }
            if (alive) stack.push_back(a);
        }
        return stack;
    }
};










































/*class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        vector<int>ans;
        ans.push_back(asteroids[0]);
        bool isalive=false;
        for(int i=1;i<asteroids.size();i++){
            isalive=true;
            while(isalive &&!ans.empty() && ans.back()>0 && asteroids[i]<0){
                if(abs(ans.back())!=abs(asteroids[i])){
                int temp=max(abs(asteroids[i]), abs(ans.pop_back()));
                ans.pop_back();
                ans.push_back(temp)

            }
        }
        return ans;
    }
};*/