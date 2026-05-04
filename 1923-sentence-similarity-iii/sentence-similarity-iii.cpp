class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.length()<s2.length()){
            swap(s1, s2);
        }
        vector<string>vec1,vec2;
        string temp;
        stringstream ss1(s1);
        while(ss1>>temp){
            vec1.push_back(temp);
        }
        stringstream ss2(s2);
        while(ss2>>temp){
            vec2.push_back(temp);
        }
       int i = 0, j = vec1.size() - 1;
        int k = 0, l = vec2.size() - 1;

        while(i<vec1.size() && k<vec2.size() && vec1[i]==vec2[k]){
            i++;
            k++;
        }
        while(k<=l && vec1[j]==vec2[l]){
            j--;
            l--;
        }
        return (k>l);
    }
};