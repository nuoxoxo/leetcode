class Solution {
public:
    bool hasAllCodes(string s, int k)
    {
        int         n = s.length();

        if (n < k)
        {
            return false;
        }

        set<string> st;
        int         i = -1;

        while (++i < n - k + 1)
        {
            st.insert(s.substr(i, k));
        }
        if (st.size() == pow(2, k))
        {
            return true;
        }
        return false;
    }
};
