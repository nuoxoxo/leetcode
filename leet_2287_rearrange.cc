class Solution {
public:
    int rearrangeCharacters(string s, string target)
    {
        // way 1 : map
        // unordered_map<char, int> S, T;

        // way 2 : vi of 26
        vector<int> S(26), T(46);
        int res = INT_MAX;
        for (char c : s)
            S[c - 'a']++;
        for (char c : target)
            T[c - 'a']++;
        int i = -1;
        while (++i < 26)
        {
            int Tcount = T[i];
            int Scount = S[i];
            if (T[i])
                res = min(res, Scount / Tcount);
        }
        return res;
    }
};
