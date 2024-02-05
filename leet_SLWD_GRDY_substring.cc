class Solution {
public:
    string minWindow(string s, string t) {
        vector< string (*) ( string, string )> Solutions {
            Greedy_sliding_window,
        };
        return Solutions[ 0/*std::rand() % Solutions.size()*/ ]( s, t );
    }

    static string Greedy_sliding_window (string s, string t)
    {
        std::unordered_map<char, int> tmap = Get_freqof_string( t );
        int slen = s.length();
        int L = 0, R = -1;
        std::unordered_map<char, int> current;
        int resL = -1, resLen = slen + 1;
        while (++R < slen)
        {
            current[s[R]]++;
            std::unordered_map<char, int>::iterator it = tmap.begin();
            bool all = true;
            while (it != tmap.end())
            {
                char c = it->first;
                if (tmap[c] > current[c])
                    all = false;
                it++;
            }
            if (all)
            {
                while (current[s[L]] > tmap[s[L]])
                {
                    current[s[L]]--;
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
        return resL > -1 ? s.substr(resL, resLen) : "";
    }

    static std::unordered_map<char, int> Get_freqof_string (string & s) {
        std::unordered_map<char, int> res;
        for (char c: s) res[ c ]++;
        return res;
    }
};
