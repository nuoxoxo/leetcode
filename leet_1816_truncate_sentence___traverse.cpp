class Solution {
public:
    string truncateSentence(string s, int k)
    {
        string  r;

        for (char c : s)
        {
            if (c == ' ')
                --k;
            if (!k)
                break ;
            r += c;
        }
        return r;
    }
};
