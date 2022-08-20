class Solution {
public:
    string truncateSentence(string s, int k)
    {
        int i = -1;

        while (++i < s.length())
        {
            if (s[i] == ' ' && --k == 0)
                break ;
        }
        return s.substr(0, i);
    }
};
