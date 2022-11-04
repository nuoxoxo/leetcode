class Solution {
public:
    string reverseVowels(string s)
    {
        char    c;
        int     i = 0, j = s.length() - 1;

        while (i < j)
        {
            // cout << i << ' ' << j << endl;
            while (i < j && !isvowel(s[i]))
                ++i;
            while (i < j && !isvowel(s[j]))
                --j;
            if (i < j)
            {
                swap(s[i], s[j]);
                // c = s[i];
                // s[i] = s[j];
                // s[j] = c;
            }
            ++i;
            --j;
        }
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
