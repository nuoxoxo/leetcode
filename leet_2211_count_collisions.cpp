class Solution {
public:
    int countCollisions(string directions)
    {
        int n = directions.length();
        int j = n - 1;
        int i = 0;
        int res = 0;
        while (i < n && directions[i] == 'L')
            ++i;
        while (j > -1 && directions[j] == 'R')
            --j;
        while (i < j + 1)
        {
            if (directions[i] != 'S')
                ++res;
            ++i;
        }
        return res;
    }
};
