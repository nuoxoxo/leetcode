class Solution {
public:
    bool isValid(string s)
    {
        map<char, char>         rule;
        stack<char>             punc;
        int                     i;

        if (!s.length())        return (true);
        if (s.length() == 1)    return (false);    
        rule['}'] = '{';
        rule[')'] = '(';
        rule[']'] = '[';
        i = -1;
        while (++i < s.length())
        {
            if (punc.size() > s.length() - 1)   return (false);
            if (rule.find(s[i]) == rule.end())  punc.push(s[i]);
            else
            {
                if (punc.size() == 0)           return (false);
                if (punc.top() != rule[s[i]])   return (false);
                punc.pop();
            }
        }
        if (punc.size())    return (false);
        return (true);
    }
};
