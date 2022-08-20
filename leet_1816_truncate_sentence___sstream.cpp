class Solution {
public:
    string truncateSentence(string s, int k)
    {
        string          r, t;
        stringstream    ss(s);

        while (k--)
        {
            ss >> t;
            r += t + ' ';
        }
        r.pop_back();
        return r;
    }
};
