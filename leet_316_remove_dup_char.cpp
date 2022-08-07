class Solution {
public:
    string removeDuplicateLetters(string s)
    {
        vector<bool>    visited(26, false);
        vector<int>     count(26);
        string          str;
        char            c;
        int             i;
        int             len = s.length();
        

        i = -1;
        while (++i < len)
        {
            c = s[i] - 'a';
            count[c] += 1 ;
        }
        i = -1;
        while (++i < len)
        {
            c = s[i] - 'a';
            if (visited[c])
                --count[c] ;
            else
            {
                while (str != "" && str.back() >= s[i] && count[str.back() - 'a'] > 1)
                {
                    --count[str.back() - 'a'] ;
                    visited[str.back() - 'a'] = false ;
                    str.pop_back();
                }
                str += s[i];
                visited[c] = true;
            }
        }
        return str ;
    }
};
