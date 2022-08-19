class Solution {
public:
    string sortSentence(string s)
    {
        vector<string>  r(9);
        string  temp, res;
        int i = -1;
        int start = 0;

        while (++i < s.length() + 1)
        {
            if (s[i] == ' ' || i == s.length())
            {
                temp = s.substr(start, i - start);
                temp.pop_back();
                temp += ' ';
                // cout << temp << endl; // debugging
                r[s[i - 1] - '0' - 1] = temp;
                start = i + 1;
            }
        }
        for (string ss : r)
            res += ss;
        res.pop_back();
        return res;
    }
};
