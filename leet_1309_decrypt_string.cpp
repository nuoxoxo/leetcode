class Solution {
public:
    string freqAlphabets(string s)
    {
        int     z = s.length();
        int     i = 0;
        string  S = "";
        while (i < z)
        {
            if (i + 2 < z && s[i + 2] == '#')
            {
                S += stoi(s.substr(i, i + 2)) - 1 + 'a';
                i += 3;
                continue ;
            }
            S += s[i] - 1 - '0' + 'a';
            ++i;
        }
        return S ;
    }
};
