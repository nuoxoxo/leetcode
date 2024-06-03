class Solution {
public:
    int appendCharacters(string s, string t)
    {
        vector<int(*)(string, string)> solutions {
            // Iterative,
            Recursive,
        };
        return solutions[0](s, t);
    }

    static int Iterative(string s, string t)
    {
        int lens = s.length(), lent = t.length();
        int si = -1, ti = 0;
        while (++si < lens)
        {
            if (s[si] == t[ti])
            {
                ti++;
                if (ti == lent)
                    return 0;
            }            
        }
        return lent - ti;
    }

    static int Recursive(string s, string t)
    {
        int lens = s.length(), lent = t.length();
        std::function<int(int, int)> recurse = [&](int si, int ti) {
            if (ti == lent)
                return 0;
            if (si == lens)
                return lent - ti;
            if (s[si] == t[ti])
                return recurse(si + 1, ti + 1);
            return recurse(si + 1, ti);
        };
        return recurse(0, 0);
    }
};
