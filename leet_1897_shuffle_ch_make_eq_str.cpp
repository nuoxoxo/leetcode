class Solution {
public:
    bool makeEqual(vector<string>& words)
    {
        map<char, int>  M;
        int             i, j;

        if (!words.size() || words.size() == 1) return true;
        i = -1;
        while (++i < words.size())
        {
            j = -1;
            while (++j < words[i].length()) M[ words[i][j] ] ++;
        }

        map<char, int>::iterator    it = M.begin();
        while (it != M.end())
        {
            if (it->second % words.size())  return (false);
            it ++;
        }
        return true;
    }
};
