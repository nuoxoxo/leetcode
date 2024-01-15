class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> D;
        int len = s.length();
        int i = -1;
        while (++i < len) {
            D[ s[i] ]++;
            D[ t[i] ]--;
        }
        int res = 0;
        auto it = D.begin();
        while (it != D.end()) {
            if (it->second > 0)
                res += it->second;
            it++;
        }
        return res;
    }
};
