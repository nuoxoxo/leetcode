class Solution {
public:
    int longestSubstring(string s, int k) {

        vector<int(*)(string, int)> Solutions {
            Fast_enough_bruteforce,
        };
        return Solutions[0](s, k);
    }

    static int Fast_enough_bruteforce(string s, int k) {
        int N = s.length();
        int end = min(N, 26);
        int res = 0;
        int uniqueChars = 0;
        while (++uniqueChars < end + 1)
        {
            unordered_map<char, int> D;
            int L = 0;
            int R = -1;
            while (++R < N)
            {
                ++D[s[R]];
                while (D.size() > uniqueChars)
                {
                    --D[s[L]];
                    if (!D[s[L]])
                        D.erase(s[L]);
                    ++L;
                }
                bool all = true;
                for (auto p: D)
                    if (p.second < k)
                        all = false;
                if (all)
                    res = max(res, R - L + 1);
            }
        }
        return res;
    }
};
