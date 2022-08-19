class Solution {
public:
    string restoreString(string s, vector<int>& indices)
    {
        string  ss = s;
        int i = -1;

        while (++i < s.length())
        {
            // ss[i] = s[indices[i]]; // wrong
            ss[indices[i]] = s[i];
        }
        return ss;
    }
};
