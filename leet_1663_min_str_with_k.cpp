class Solution {
public:
    string getSmallestString(int n, int k)
    {
        string          res ;
        int             i ;

        i = -1;
        while (++i < n)
        {
            res += 'a';
            -- k ;
        }
        cout << res << endl;
        i = n;
        while (--i > -1)
        {
            if (k > 25)
            {
                k -= 25 ;
                res[i] = 'z';
            }
            else
            {
                res[i] += k ;
                break ;
            }
        }
        return res ;
    }
};
