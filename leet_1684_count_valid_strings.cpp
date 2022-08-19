class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words)
    {
        bool    ok;
        int     r = 0;

        for (string w : words)
        {
            ok = true;
            for (char c : w)
            {
                if (find(allowed.begin(), allowed.end(), c) == allowed.end())
                {
                    ok = false;
                    break ;
                }
            }
            if (ok)
                r++;
        }
        return r;
    }
};
