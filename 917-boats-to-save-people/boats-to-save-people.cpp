class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        sort(people.begin(), people.end());
        int i=0;
        int j=people.size()-1;
        int boat=0;
        while(i<=j){
            int sum=people[i]+people[j];
            if(sum<=limit){
                boat++;
                i++;
                j--;

            }
            else {
                j--;
                boat++;

            }
            
            
        }
        return boat;
    }
};