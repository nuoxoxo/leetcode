class Solution {
public:
    string toLowerCase(string s)
    {
        int i = -1;
        while (++i < s.length())
            if (s[i] <= 'Z' && s[i] >= 'A')
                s[i] -= 'A' - 'a';
        return s;
    }
};
