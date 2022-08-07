class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words)
    {
        int     lw, i;

        lw = words.size();
        for (string w: words)
        {
            i = 0;
            for (char c: w)
            {
                i = s.find_first_of(c, i); // find first occurrence of c from index i
                if (i == string::npos)
                {
                    lw -= 1;
                    break ;
                }
                i += 1;
            }
        }
        return lw;
    }
};
