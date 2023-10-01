/*

                1
            .5      .5 of prev
        .25     .5      .25
    .125    .625    .625    .125

                1
            1/2     1/2             (of prev)
        1/2     .5+.5   1/2         (of prev)
    1/2     .5+.5   .5+.5   1/2     (of prev)
1/2     .5+.5   .5+.5   .5+.5   1/2 (of prev)

*/

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<double>  level = { (double) poured };
        int n = 0;
        while (++n < query_row + 1)
        {
            vector<double>  next_level ;
            int i = -1;
            while (++i < n + 1)
                next_level.push_back((double) 0);
            i = -1;
            while (++i < n + 1)
            {
                double  L = 0;
                double  R = 0;
                double  Lo = 0; // overflow
                double  Ro = 0;
                if (i > 0)
                    L = level[i - 1];
                if (i < (int) level.size())
                    R = level[i];
                if (L - 1 > 0)
                    Lo = L - 1;
                if (R - 1 > 0)
                    Ro = R - 1;
                next_level[i] = Lo * .5 + Ro * .5;
                /*
                cout << n << ':' << i << ':';
                cout << L << ' ' << R << ' ';
                cout << Lo << ' ' << Ro << ' ';
                cout << next_level[i] << '\n';
                */
            }
            level = next_level;
        }
        double res = level[query_glass];
        return res > 1 ? 1 : res;
    }
};
