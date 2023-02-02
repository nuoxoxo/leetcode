class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order)
    {
        map<char, int>  E ;
        int             i, j;

        i = -1;
        while (++i < order.size())
            E[order[i]] = i;
        i = -1;
        while (++i < words.size() - 1)
        {
            string  s1 = words[i];
            string  s2 = words[i + 1];
    
            j = -1;
            while (++j < s1.length())
            {
                if (j == s2.length())
                    return false ;
                if (s1[j] != s2[j])
                {
                    if (E[s1[j]] > E[s2[j]])
                        return false ;
                    break ;
                }
            }
        }
        return true ;
    }
};
