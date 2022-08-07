class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k)
    {
        int         n = chalk.size();
        int         i = 0;
        long long   t = 0;
        
        for (int c: chalk)
            t += c;
        k %= t;
        while (true)
        {
            if (k < chalk[i])
                return i;
            k -= chalk[i];
            i += 1;
            i %= n;
        }
        return -1;
    }
};
