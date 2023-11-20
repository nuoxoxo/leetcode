class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel)
    {
        // new

        // starting point for each of 3 gb types
        string  start = garbage[0];
        int gg = count_if(start.begin(), start.end(), [](char c){ return c == 'G';});
        int pp = count_if(start.begin(), start.end(), [](char c){ return c == 'P';});
        int mm = count_if(start.begin(), start.end(), [](char c){ return c == 'M';});
        int g = gg, m = mm, p = pp;
        int i = 0;
        while (++i < (int)garbage.size())
        {
            int t = travel[i - 1];
            gg += t;
            pp += t;
            mm += t;
            string s = garbage[i];
            int ifg = count_if(s.begin(), s.end(), [](char c){ return c == 'G';});
            int ifp = count_if(s.begin(), s.end(), [](char c){ return c == 'P';});
            int ifm = count_if(s.begin(), s.end(), [](char c){ return c == 'M';});
            gg += ifg;
            pp += ifp;
            mm += ifm;
            if (ifg)
                g = gg;
            if (ifp)
                p = pp;
            if (ifm)
                m = mm;
        }
        return g + m + p;

        // ------------ line ------------ //

        // raw

        /*
        int res = 0;
        // starting point for each of 3 gb types
        string  start = garbage[0];
        int gg = count_if(start.begin(), start.end(), [](char c){ return c == 'G';});
        int pp = count_if(start.begin(), start.end(), [](char c){ return c == 'P';});
        int mm = count_if(start.begin(), start.end(), [](char c){ return c == 'M';});
        // cout << gg << ' ' << pp << ' ' << mm << '\n';
        int g = gg, m = mm, p = pp;
        int i = 0;
        while (++i < (int)garbage.size())
        {
            int t = travel[i - 1];
            gg += t;
            pp += t;
            mm += t;
            // cout << gg << ' ' << pp << ' ' << mm << '\n';
            string s = garbage[i];
            if (s.find('G') != std::string::npos)
            {
                gg += count_if(s.begin(), s.end(), [](char c){ return c == 'G';});
                g = gg;
            }
            if (s.find('P') != std::string::npos)
            {
                pp += count_if(s.begin(), s.end(), [](char c){ return c == 'P';});
                p = pp;
            }
            if (s.find('M') != std::string::npos)
            {
                mm += count_if(s.begin(), s.end(), [](char c){ return c == 'M';});
                m = mm;
            }
            // cout << gg << ' ' << pp << ' ' << mm << '\n';
        }
        // cout << g << ' ' << p << ' ' << m << '\n';
        return g + m + p;
        */
    }
};
