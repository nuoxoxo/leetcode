class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int len, res, i, j;

        len = s.length();
        if (!len || len == 1)
            return len;

        //  step 1 - suppose ending chars are repeated

        i = len - 1;
        while (i > -1)
        {
            if (i - 1 > -1 && s[i] == s[i - 1])
                --i;
            else
                break;
        }
        len = i + 1;

        //  step 2 - leading chars too

        i = 0;
        while (i < len)
        {
            if (i + 1 < len && s[i] == s[i + 1])
               ++i;
            else
                break;
        }

        //  step 3 - now we have a range

        res = 0;
        while (i < len)
        {
            map<char, int>  m;
            j = i - 1;
            while (++j < len)
            {
                if (!m[s[j]])
                    ++m[s[j]];
                else
                    break;
            }
            res = max(res, (int) m.size());
            ++i;
        }
        return res;
    }
};
