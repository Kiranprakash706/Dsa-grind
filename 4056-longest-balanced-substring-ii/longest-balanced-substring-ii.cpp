class Solution {
public:
    //TC = O(n)    &&   SC = O(n)
    int helper(string &s, char ch1, char ch2) {
        int n = s.size();

        unordered_map<int, int> diffMap;

        int count1 = 0;
        int count2 = 0;

        int maxL = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] != ch1 && s[i] != ch2) {
                diffMap.clear();
                count1 = 0;
                count2 = 0;

                continue;
            }

            if(s[i] == ch1) {
                count1++;
            }

            if(s[i] == ch2) {
                count2++;
            }

            if(count1 == count2) {
                maxL = max(maxL, count1+count2);
            }

            int diff = count1 - count2;

            if(diffMap.count(diff)) {
                maxL = max(maxL, i - diffMap[diff]);
            }
            else {
                diffMap[diff] = i;
            }
        }

        return maxL;
    }

    int longestBalanced(string s) {
        int n = s.size();

        int count = 1; //s[0]
        int maxLen = 0;

        //CASE - 1 aaaa, bbbb, cccc
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) {
                count++;
            }
            else {
                maxLen = max(maxLen, count);
                count = 1;
            }
        }

        maxLen = max(maxLen, count);

        //CASE - 2
        maxLen = max(maxLen, helper(s, 'a', 'b'));
        maxLen = max(maxLen, helper(s, 'a', 'c'));
        maxLen = max(maxLen, helper(s, 'b', 'c'));

        //CASE - 3
        int countA = 0;
        int countB = 0;
        int countC = 0;

        unordered_map<string, int> diffMap;

        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') {
                countA++;
            }

            if(s[i] == 'b') {
                countB++;
            }

            if(s[i] == 'c') {
                countC++;
            }

            if(countA == countB && countA == countC) {
                maxLen = max(maxLen, countA+countB+countC);
            }

            int diffAB = countA - countB;
            int diffAC = countA - countC;

            string key = to_string(diffAB) + "_" + to_string(diffAC);

            if(diffMap.count(key)) {
                maxLen = max(maxLen, i - diffMap[key]);
            }
            else {
                diffMap[key] = i;
            }
        }

        return maxLen;
    }
};