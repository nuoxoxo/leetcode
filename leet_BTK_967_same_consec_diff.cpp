class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k)
    {
        vector<int> r;
        string      s;
        backtrack(r, s, n, k);
        return r;
    }

    void    backtrack(vector<int>& r, string& s, int n, int k)
    {
        int     last, i; // last single digit of the current &s

        if (s.length() == n)
            return r.push_back(stoi(s));
        if (s.length() == 0)
            last = -1;
        else
            last = s.back() - '0';
        i = -1;
        while (++i < 10)
        {
            if (last == -1 && i == 0)
                continue ;
            if (last == -1 || abs(last - i) == k)
            {
                s += i + '0';
                backtrack(r, s, n, k);
                s.pop_back();
            }
        }
    }
};
