class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words)
    {
        vector<string>  res;
        int             i = 0;
        int             len = words.size();

        res.push_back(words[0]);
        while (++i < len)
        {
            string  L = words[i - 1];
            string  R = words[i];

            sort(L.begin(), L.end());
            sort(R.begin(), R.end());
            while (L == R)
            {
                ++i;
                if (i > len - 1)
                    break;
                R = words[i];
                sort(R.begin(), R.end());
            }
            if (i > len - 1)
                break;
            res.push_back(words[i]);
        }
        return res ;
    }
};
