class Solution {
public:
    string makeGood(string s)
    {
        vector<string(*)(string)> Solutions {
            // Push_first,
            Scan_first,
        };
        return Solutions[0](s);
    }

    static string Scan_first(string s)
    {
        deque<char> dq;
        for (char c: s)
        {
            int N = dq.size();
            if (N && (c ^ dq[N - 1]) == 32)
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
