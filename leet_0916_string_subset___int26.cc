class Solution {
public:
    vector<string> wordSubsets(vector<string>& g1, vector<string>& g2)
    {
        vector<string>      res;

        int     i;
        int     n1 = g1.size();
        int     n2 = g2.size();
        int     freq[26] = {0};

        for (string w: g2)
        {
            int     temp[26] = {0};

            for (char c: w)
            {
                temp[c - 'a'] += 1;
                freq[c - 'a'] = max(freq[c - 'a'], temp[c - 'a']);
            }
        }
        for (string w: g1)
        {
            int     temp[26] = {0};

            for (char c: w)
            {
                temp[c - 'a'] += 1;
            }
            i = -1;
            while (++i < 26 && temp[i] >= freq[i])
                ;
            if (i == 26)
                res.push_back(w);
        }
        return (res);
    }
};
