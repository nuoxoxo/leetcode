class Solution {
public:
    string minRemoveToMakeValid(string s)
    {
        std::deque<int>     d ;
        std::string         res = "";
        int                 i = -1, len = s.length();

        while (++i < len)
        {
            if (s[i] == ')')
            {
                if (d.empty())
                    s[i] = '_';
                else
                    d.pop_back();
            }
            if (s[i] == '(')
                d.push_back(i);
        }
        while (!(d.empty()))    
        {
            s[ d.front() ] = '_';
            d.pop_front();
        }
        i = -1;
        while (++i < len)
        {
            if (s[i] != '_')
                res += s[i];
        }
        return res ;
    }
};
