class Solution {
public:
    string reverseVowels(string s)
    {
        vector<char>    c;
        vector<int>     idx;
        int             i = -1;

        while (++i < s.length())
        {
            if (isvowel(s[i]))
            {
                idx.push_back(i);
                c.push_back(s[i]);
            }
        }
        reverse(c.begin(), c.end());
        i = 0;
        for (int n : idx)
            s[n] = c[i++];
        return s;
    }

    int isvowel(char c)
    {
        if (c ^ 'a' && c ^ 'e' && c ^ 'i' && c ^ 'o' && c ^ 'u' &&
           c ^ 'A' && c ^ 'E' && c ^ 'I' && c ^ 'O' && c ^ 'U')
            return 0;
        return 1;
    }
};
