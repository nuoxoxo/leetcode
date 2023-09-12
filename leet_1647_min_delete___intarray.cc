class Solution {
public:
    int minDeletions(string s)
    {
        int count[26] = {0};
        int i = -1, res = 0;
        i = -1;
        while (++i < s.length())
            ++count[s[i] - 'a'];
        i = -1;
        sort(count, count + 25);
        while (++i < 25)
        {
            if (!count[i] || count[i] != count[i + 1])
                continue ;
            --count[i];
            ++res;
            i = -1;
        }
        return res;
    }
};;
