class Solution {
public:
    bool canPlaceFlowers(vector<int>& FB, int n)
    {
        int L = FB.size(), interval = 0, i = -1;

        if (L == 1 && !FB[0])   return true ;
        while (++i < L + 1)
        {
            if (i < L && !FB[i])
            {
                if (i == 0 || i == L - 1)
                    interval++;
                interval++;
            }
            else
            {
                n -= (interval - 1) / 2;
                if (n < 1)  return true ;
                interval = 0;
            }
        }
        return false ;
    }
};

/*
[0]
1
[0,1,0]
1
[1,0,0,0,1]
1
[1,0,0,0,1]
2
[1,0,0,0,1,0,0]
2
*/
