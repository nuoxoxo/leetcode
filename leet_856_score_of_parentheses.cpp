class Solution {
public:
    int scoreOfParentheses(string s)
    {
        deque<int>  D;
        int         res;

        res = 0 ;
        for (char c: s)
        {
            if (c == '(')
            {
                D.push_back(res);
                res = 0;
            }
            else
            {
                res += D.back() + max(res, 1);
                D.pop_back();
            }
        }
        return res ;
    }
};
