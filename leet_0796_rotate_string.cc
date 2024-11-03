class Solution {
public:
    bool rotateString(string s, string g) {
        if (s == g) return true;
        int len = s.length();
        if (len ^ g.length() || len == 1)
            return false;
        while (len--)
        {
            g += g[0];
            g.erase(g.begin());
            if (s == g) return true;
        }
        return false ;
    }
};
