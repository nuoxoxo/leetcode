class Solution {
public:
    int maxDepth(string s)
    {
        int r = 0, t = 0;

        for (char c : s)
        {
            if (c == '(')
                ++t;
            if (c == ')')
                --t;
            if (r < t)
                r = t;
        }
        return r;
    }
};
