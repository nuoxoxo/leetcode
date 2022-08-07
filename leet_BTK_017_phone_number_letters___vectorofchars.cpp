class Solution {
public:

    vector<string>  buttons{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits)
    {
        if (!digits.length())
            return {};
        vector<char>    c;
        vector<string>  v;
        backtracking(digits, c, v, 0);
        return v ;
    }

    void    backtracking(string digits, vector<char> c, vector<string> &v, int i)
    {
        if (i == digits.length())
        {
            string  res(c.begin(), c.end());
            v.push_back(res);
        }
        else
        {
            int n = digits[i] - '0';
            int j = -1;
            while (++j < buttons[n].length())
            {
                c.push_back(buttons[n][j]);
                backtracking(digits, c, v, i + 1);
                c.pop_back();
            }
        }
    }
};
