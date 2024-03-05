class Solution {
public:
    int minimumLength(string s) {
        int N = (int)s.length();
        int l = 0, r = N - 1;
        char c;
        while (l < r) {
            if (s[l] == s[r]) {
                c = s[l];
                while (l <= r && c == s[l]) {
                    ++l;
                }
                while (l <= r && c == s[r]) {
                    --r;
                }
            } else break;
        }
        return r + 1 - l;
    }
};
