class Solution {
public:
    string reverseWords(string s)
    {
        stringstream    ss(s);
        string          temp, res;

        while (ss >> temp)
        {
            reverse(temp.begin(), temp.end());
            res += temp + ' ';
        }
        return res.substr(0, res.length() - 1);
    }
};
