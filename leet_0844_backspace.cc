class Solution {
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
};

/*
"xywrrmp"
"xywrrmu#p"
"a##c"
"#a#c"
*/
