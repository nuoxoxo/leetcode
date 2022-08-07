class Solution {
public:
    int countSegments(string s)
    {
        stringstream    ss(s);
        string          w;
        int             res = 0;
        while (ss >> w)
            ++ res;
        return res;
    }
};
