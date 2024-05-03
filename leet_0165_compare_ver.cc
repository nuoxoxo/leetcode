class Solution {
public:
    int compareVersion(string version1, string version2)
    {

        vector<int(*)(string, string)> solutions {
            Linear_time,
            // Extra_space,
        };
        return solutions[0](version1, version2);
    }

    static int Linear_time(string v1, string v2)
    {
        int size1 = v1.size(), size2 = v2.size();
        int l = 0, r = 0;
        while (l < size1 || r < size2)
        {
            int L = 0;
            int ll = l;
            while (ll < size1 && v1[ll] != '.')
            {
                L *= 10;
                L += v1[ll] - '0';
                ll++;
            }
            int R = 0;
            int rr = r;
            while (rr < size2 && v2[rr] != '.')
            {
                R *= 10;
                R += v2[rr] - '0';
                rr++;
            }
            if (L < R)
                return -1;
            if (L > R)
                return 1;
            l = ll + 1;
            r = rr + 1;
        }
        return 0;
    }

    static int Extra_space(string v1, string v2)
    {

        vector<int> L, R;
        std::stringstream ss(v1);
        string s;
        while (getline(ss, s, '.'))
            L.push_back(stoi(s));
        ss.clear();
        ss.str(v2);
        while (getline(ss, s, '.'))
            R.push_back(stoi(s));
        while (L.size() < R.size())
            L.push_back(0);
        while (L.size() > R.size())
            R.push_back(0);
        int N = L.size(), i = -1;
        while (++i < N)
        {
            int l = L[i], r = R[i];
            if (l < r)
                return -1;
            if (l > r)
                return 1;
        }
        return 0;
    }
};

/*
version1 = "0.1" === version2 = "1.1"
version1 = "1.0" === version2 = "1.0.0"
*/

