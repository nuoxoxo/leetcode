class Solution {
public:
    int countHomogenous(string s)
    {
        if (s == "")
            return 0;
        long long MD = 1e9 + 7;
        long long res = 0;
        char c = s[0];
        int len = s.size();
        int dis = 1;
        int i = 0;
        while (++i < len)
        {
            if (c == s[i])
            {
                dis++;
            }
            else
            {
                res += ((dis % MD + 1) * dis % MD / 2) % MD;
                c = s[i];
                dis = 1;
            }
        }
        return res + ((dis % MD + 1) * dis % MD / 2) % MD;
        // return res;
    }
};
