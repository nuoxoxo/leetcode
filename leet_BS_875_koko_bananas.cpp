/* ******************************************** */
/*                                              */
/*              \\             /`/``            */
/*              ~\o o_       0 0\               */
/*              / \__)      (u  ); _  _         */
/*       / \/ \/  /           \  \/ \/ \        */
/*      /(   . . )            (         )\      */
/*     /  \_____/              \_______/  \     */
/*         []  []               [[] [[]    *.   */
/*         []] []]              [[] [[]         */
/*                                              */
/* ************************************ nuo *** */

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h)
    {
        int L, R, size, res;

        sort(piles.begin(), piles.end());
        size = piles.size();
        res = piles[size - 1];
        R = res;
        L = 1;

        while (L <= R)
        {
            int mid, i, t;

            t = 0;
            i = -1;
            mid = (L + R) / 2;
            while (++i < size)
            {
                int n = piles[i];

                // if (n != mid)   t += n / mid; // initial wrong solve 
                if (!(n % mid)) t += n / mid;
                else            t += n / mid + 1; // crucial fix
            }
            // cout << L << ' ' << R << ' ' << t << ' ' << res << endl;
            if (t > h)
            {
                L = mid + 1;
            }
            else
            {
                res = res < mid ? res : mid ;
                R = mid - 1;
            }
        }
        return res ;
    }
};


