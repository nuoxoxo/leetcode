class Solution {
public:
    int minDeletionSize(vector<string>& strs)
    {
        int ls = strs[0].length();
        vector<string> a(ls);
        int i = -1;
        while (++i < ls)
        {
            for (string & s: strs)
                a[i] += s[i];
        }
        int r = 0;
        for (string &s : a)
        {
            string temp = s;
            sort(s.begin(), s.end());
            if (s != temp)
                r += 1;
        }
        return r;
    }
};
