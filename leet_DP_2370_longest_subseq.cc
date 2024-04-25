class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> lens(26, 0);
        // lens: each cell
        //      - `the longest strlen within a window [i-k, i+k+1)`
        //      - L bound: max(0, i-k)
        //      - R bound: min(i+k+1, 26)
        for (char c: s) {
            int idx = c - 'a';
            int L = idx - k;
            L = L < 0 ? 0 : L;
            int R = idx + k + 1;
            R = R < 26 ? R : 26;
            int best = *std::max_element(lens.begin() + L, lens.begin() + R);
            lens[idx] = best + 1;
        }
        return *std::max_element(lens.begin(), lens.end());
    }
};
