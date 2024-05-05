class Solution {
public:
    vector<int> diStringMatch(string s)
    {
        vector<int> res;
        int N = s.length();
        int l = 0;
        int r = N;
        for (char c: s)
        {
            if (c == 'I')
                res.push_back(l++);
            else if (c == 'D')
                res.push_back(r--);
        }
        res.push_back(l);
        return res;
    }
};
