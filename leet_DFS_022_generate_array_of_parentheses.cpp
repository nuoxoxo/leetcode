class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string>  res ;
        string          s;

        s = "";
        solver(n, n, s, res);

        return res ;
    }
    
    void    solver(int open, int close, string& s, vector<string>& res)
    {
        if (!open && !close)
        {
            res.push_back(s);
            return ;
        }
        if (open)
        {
            s += '(';
            solver(open - 1, close, s, res);
            s.pop_back();
        }
        if (open < close)
        {
            s += ')';
            solver(open, close - 1, s, res);
            s.pop_back();
        }
    }
};
