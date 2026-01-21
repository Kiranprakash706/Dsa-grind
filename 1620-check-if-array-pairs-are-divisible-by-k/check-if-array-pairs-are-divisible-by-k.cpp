class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> mapp;
        int count = 0;

        for (int i = 0; i < arr.size(); i++) {
            int temp =((arr[i] % k)+k)%k;

            if (temp == 0) {
                if(mapp.find(0)!=mapp.end()){
                    count++;
                    if(mapp[0]>1){
                        mapp[0]--;
                    }
                    else{
                        mapp.erase(0);
                    }
                }
                else{
                    mapp[0]++;
                }
            }
            else if (mapp.find(k - temp) != mapp.end()) {
                count++;
                if (mapp[k - temp] == 1) {
                    mapp.erase(k - temp);
                } else {
                    mapp[k - temp]--;
                }
            }
            else {
                mapp[temp]++;
            }
        }
        return count == arr.size() / 2;
    }
};
