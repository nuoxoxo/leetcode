class Solution {
public:
    bool isAnagram(string s, string t)
    {
        int     mp[26], len, i;

        len = s.length();
        if (len != t.length())
            return false;
        fill(begin(mp), end(mp), 0);
        i = -1;
        while (++i < len)
        {
            ++mp[s[i] - 'a'];
            --mp[t[i] - 'a'];
        }
        i = -1;
        while (++i < 26 && !mp[i])
            ;
        if (i == 26)
            return true;
        cout << i << endl;
        return false;
    }
};
