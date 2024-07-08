class Solution {
public:
    int passThePillow(int n, int time)
    {
        // 1,2,3,4,...,n-1,n
        int i = 1;
        int dir = 1;
        while (time)
        {
            i += dir;
            time--;
            if (i == n || i == 1)
                dir ^= -2; // small trick flips it btw -1 and 1
        }
        return i;

        // 2nd soln
        // math
    }
};
