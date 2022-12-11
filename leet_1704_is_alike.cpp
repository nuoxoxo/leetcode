class Solution {
public:
    bool halvesAreAlike(string s)
    {
        int l, r;
        int len = s.length();
        int ll = 0, rr = 0, i = -1;

        while (++i < len / 2)
        {
            r = tolower(s[i]);
            l = tolower(s[i + len / 2]);
            if (l == 'a' || l == 'e' || l == 'i' | l == 'o' || l == 'u')
                ++ll;
            if (r == 'a' || r == 'e' || r == 'i' | r == 'o' || r == 'u')
                ++rr;
        }
        return (rr == ll);
    }
};
