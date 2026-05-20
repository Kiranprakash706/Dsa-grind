class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
    vector<int> prefixCommon(n, 0); // Resultant array
    unordered_set<int> seenA, seenB; // Sets to track seen elements in A and B

    for (int i = 0; i < n; ++i) {
        // Insert current elements of A and B into their respective sets
        seenA.insert(A[i]);
        seenB.insert(B[i]);

        // Count common elements between seenA and seenB
        int commonCount = 0;
        for (const auto& elem : seenA) {
            if (seenB.count(elem)) {
                ++commonCount;
            }
        }
        prefixCommon[i] = commonCount;
    }

    return prefixCommon;
    }
};