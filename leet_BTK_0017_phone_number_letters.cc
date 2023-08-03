class Solution {
public:
    
    vector<string>  buttons{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    vector<string> letterCombinations(string digits)
    {
        if (!digits.length())
            return {};
        vector<string>  v;
        string          test;
        backtracking(digits, test, v, 0);
        return v ;
    }

    void    backtracking(string d, string test, vector<string>& v, int index)
    {
        if (index == d.length())
            v.push_back(test);
        else
        {
            int n = d[index] - '0';
            int i = -1;
            while (++i < buttons[n].length())
            {
                test += buttons[n][i];
                backtracking(d, test, v, index + 1);
                test.pop_back();
            }
        }
    }
};
