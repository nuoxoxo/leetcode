class Solution {
public:
    string minWindow(string s, string t) {
        vector< string (*) ( string, string )> Solutions {
            Greedy_sliding_window,
            // Solution_1,
        };
        return Solutions[ std::rand() % Solutions.size() ]( s, t );
    }

    static string Greedy_sliding_window (string s, string t)
    {
        std::unordered_map<string, int> tmap = Get_freqof_string( t );
        int slen = s.length();
        int L = 0, R = -1;
        std::unordered_map<string, int> current;
        int resL = -1, resLen = slen + 1;
        while (++R < slen)
        {
            current[string(1, s[R])]++;
            // current[s.substr(R, R - L + 1)]++;
            std::unordered_map<string, int>::iterator it = tmap.begin();
            bool all = true;
            while (it != tmap.end())
            {
                string c = it->first;
                if (tmap[c] > current[c])
                    all = false;
                it++;
            }
            if (all)
            {
                while (current[string(1, s[L])] > tmap[string(1, s[L])])
                {
                    current[string(1, s[L])]--;
                    L++;
                }
                int possible_len = R - L + 1;
                if (possible_len < resLen)
                {
                    resL = L;
                    resLen = possible_len;
                }
            }
        }
        if (resL < 0)
        {
            cout << resL << ' ' << resLen << endl;
            return "";
        }
        return s.substr(resL, resLen);
    }

    static std::unordered_map<string, int> Get_freqof_string (string & s) {
        std::unordered_map<string, int> res;
        for (char c: s) res[string(1, c)]++;
        return res;
    }
};
