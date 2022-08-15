
/*
Symbol       Value
I             1         .           . case V . case X
V             5         . priority
X             10        .           . case L . case C
L             50        . priority
C             100       .           . case D . case M
D             500       . priority
M             1000      . priority
*/
    
int romanToInt(char * s)
{
    int         res = 0;
    int         i = 0;
    char        c, c2;

    while (s[i])
    {
        c = s[i];

        /* priority group : V L D M  ( the Voldemort group ) */

        if (c == 'M')
            res += 1000;
        else if (c == 'D')
            res += 500;
        else if (c == 'L')
            res += 50;
        else if (c == 'V')
            res += 5;

        /* four-nine group : either 4 or 9 ( or basecase of 1 ) */

        /* CD . CM . just C */

        else if (c == 'C')
        {
            if (s[i + 1] && s[i + 1] == 'D')
            {
                res += 400;
                i += 1;
            }
            else if (s[i + 1] && s[i + 1] == 'M')
            {
                res += 900;
                i += 1;
            }
            //  basecase just c
            else
            {
                res += 100;
            }
        }

        /* XL . XC . just X */

        else if (c == 'X')
        {
            if (s[i + 1] && s[i + 1] == 'L')
            {
                res += 40;
                i += 1;
            }
            else if (s[i + 1] && s[i + 1] == 'C')
            {
                res += 90;
                i += 1;
            }
            //  basecase just x
            else
            {
                res += 10;
            }
        }

        /* IV . IX . just I */

        else if (c == 'I')
        {
            if (s[i + 1] && s[i + 1] == 'V')
            {
                res += 4;
                i += 1;
            }
            else if (s[i + 1] && s[i + 1] == 'X')
            {
                res += 9;
                i += 1;
            }
            else
            {
                res += 1;
            }
        }
        i += 1;
    }
    return res;
}







