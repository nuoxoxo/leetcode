class Solution {
public:
    bool backspaceCompare(string s, string t)
    {
        deque<char> ss, tt;
        for (char c: s)
        {
            if (c ^ '#')
                ss.push_back(c);
            else if (!ss.empty())
                ss.pop_back();
        }
        for (char c: t)
        {
            if (c ^ '#')
                tt.push_back(c);
            else if (!tt.empty())
                tt.pop_back();
        }
        return ss == tt ;
    }
};

/*class Solution {
public:
    bool backspaceCompare(string s, string t)
    {
        deque<char> ss, tt;
        int         i;

        i = -1;
        while (++i < s.length())
        {
            if (s[i] ^ '#')
                ss.push_back(s[i]);
            else if (!ss.empty())
                ss.pop_back();
        }
        i = -1;
        while (++i < t.length())
        {
            if (t[i] ^ '#')
                tt.push_back(t[i]);
            else if (!tt.empty())
                tt.pop_back();
        }
        return ss == tt ;
    }
};*/

/*
"xywrrmp"
"xywrrmu#p"
"a##c"
"#a#c"
*/
