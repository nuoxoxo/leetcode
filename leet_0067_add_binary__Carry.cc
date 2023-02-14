class Solution {
public:
    string addBinary(string a, string b)
    {
        int     lena = a.length();
        int     lenb = b.length();
        int     diff = abs(lena - lenb);
        int     len = max(lena , lenb);
        int     carry, i ;
        string  ones = "";
        string  E = "";
        string  s = "";
        string  r = "";

        i = -1;
        while (++i < diff)
            s += '0';
        if (lena ^ len)
            a = s + a;
        if (lenb ^ len)
            b = s + b;
        i = -1;
        while (++i < len)
            E += a[i] + b[i] - '0';
        carry = 0;
        i = len ;
        while (--i > -1)
        {
            char    c = E[i];

            if (c == '0')
            {
                if (!carry) r += '0';
                else
                {
                    carry -- ;
                    r += '1';
                }
            }
            if (c == '1')
            {
                if (!carry) r += '1';
                else        r += '0';
            }
            if (c == '2')
            {
                if (!carry)
                {
                    carry ++ ;
                    r += '0';
                }
                else
                    r += '1';
            }
        }
        if (carry)
        {
            i = -1;
            while (++i < carry)
                ones += '1';
        }
        reverse(r.begin(), r.end());

        return ones + r ;
    }
};
