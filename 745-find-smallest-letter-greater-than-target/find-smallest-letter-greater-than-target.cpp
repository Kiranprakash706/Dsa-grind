class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();

        int ans = upper_bound(letters.begin(), letters.end(), target) - letters.begin();
        
        return ans == n ? letters[0] : letters[ans];
    }
};