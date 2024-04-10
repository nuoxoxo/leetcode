class Solution {
public:
    string makeGood(string s)
    {
        vector<string(*)(string)> Solutions {
            // Push_first,
            // Scan_first,
            String_based_fastest_approach,
        };
        return Solutions[0](s);
    }

    // BEST Soln

    static string String_based_fastest_approach(string s)
    {
        string res;
        for (char c: s)
        {
            if (!res.empty() && (c ^ res.back()) == 32)
                res.pop_back();
            else
                res.push_back(c);
        }
        return res;
    }

    static string Scan_first(string s)
    {
        deque<char> dq;
        for (char c: s)
        {
            if (!dq.empty() && (c ^ dq.back()) == 32)
                dq.pop_back();
            else
                dq.push_back(c);
        }
        string res = "";
        for (char c: dq)
            res += c;
        return res;
    }

    static string Push_first(string s)
    {
        deque<char> dq;
        int i = -1;
        for (char c: s)
        {
            dq.push_back(c);
            int N = dq.size();
            if (N > 1 && (dq[N - 1] ^ dq[N - 2]) == 32)
            {
                dq.pop_back();
                dq.pop_back();
            }
        }
        string res = "";
        for (char c: dq)
            res += c;
        return res;
    }
};
