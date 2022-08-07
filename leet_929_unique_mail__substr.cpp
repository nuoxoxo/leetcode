class Solution {
public:
    int numUniqueEmails(vector<string>& emails)
    {
        int         i, n;
        set<string> s;

        for (string m: emails)
        {
            i = 0;
            n = m.length();
            while (m[i] != '@')
                ++i;
            string  head = make(m.substr(0, i));
            string  tail = m.substr(i + 1, n - 1 - i);
            string  news = head + '@' + tail;
            s.insert(news);
        }
        return (int) s.size() ;
    }

    string  make(string s)
    {
        int     i = -1;
        string  res;
        
        while (++i < s.length() && s[i] != '+')
            if (s[i] != '.')
                res += s[i];
        return res ;
    }
};
