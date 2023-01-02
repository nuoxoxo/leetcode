class Solution {
public:
    bool detectCapitalUse(string s)
    {
        if (s.length() == 1)
            return true;
        char c = s[0];
        int i;
        if (c >= 'a')
        {
            i = 0;
            while (++i < s.length())
            {
                if (s[i] <= 'Z')
                    return false;
            }
        }
        else if (c > 'Z')
            return false;
        c = s[1];
        if (c >= 'a')
        {
            i = 1;
            while (++i < s.length())
            {
                if (s[i] <= 'Z')
                    return false;
            }
        }
        else if (c <= 'Z')
        {
            i = 1;
            while (++i < s.length())
            {
                if (s[i] >= 'a')
                    return false;
            }
        }
        return true;
    }
};
