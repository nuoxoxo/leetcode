class Solution {
public:
    string reverseParentheses(string s)
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
