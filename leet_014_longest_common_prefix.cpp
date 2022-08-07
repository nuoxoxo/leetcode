class Solution {
public:
    string  longestCommonPrefix(vector<string>& strs)
    {
            int     i, j;
            string  s;

            if (!strs.size() || !strs[0].length())  return (s);
            if (strs.size() < 2)    return (strs[0]);
            i = 0;
            while (i < strs[0].length())
            {
                j = 1;
                while (j < strs.size() && strs[j][i] == strs[0][i]) j++;
                if ( j == strs.size() ) s += strs[0][i];
                else    break;
                i++;
            }
            return (s);
    }
};
