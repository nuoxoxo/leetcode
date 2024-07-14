class Solution {
public:
    string reverseParentheses(string s)
    {
        vector<string(*)(string)> solutions = {
            // Initial_soln,
            Faster_reverse_inplace,
        };
        return solutions[0]( s );
    }

    static string Faster_reverse_inplace(string s)
    {
        deque<int> Q;
        string res;
        for (char c : s)
        {
            if (c == '(')
            {
                Q.push_back( res.length() );
            }
            else if (c == ')')
            {
                int left = Q.back();
                Q.pop_back();
                reverse(begin(res) + left, end(res));
            }
            else
            {
                res += c;
            }
        }
        return res;
    }

    static string Initial_soln(string s)
    {
        deque<int> Q;
        string res;
        int N = s.length();
        int i = -1;
        while (++i < N)
        {
            char c = s[i];
            if (c == '(')
                Q.push_back(i);    
            else if (c == ')')
            {
                int left = Q.back();
                Q.pop_back();
                // cout << "1/ " << s << endl;
                reverse(s.begin() + left + 1, s.begin() + i);
                // cout << "2/ " << s << endl;
            }
        }
        for (auto c : s)
            if (c != '(' && c != ')')
                res += c;
        return res;
    }
};
