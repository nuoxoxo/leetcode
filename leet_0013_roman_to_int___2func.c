
int     bf(char c); // bf = brute-force

int romanToInt(char *s)
{
    int     self, next, res, i;

    res = 0;
    i = 0;
    while (s[i])
    {
        self = bf(s[i]);
        next = s[i + 1] ? bf(s[i + 1]) : 0;    
        if (self < next) 
        {
            res += next - self;
            i += 1;
        }
        else
        {
            res += self; 
        }
        i += 1;
    }
    return res;
}

int     bf(char c)
{
    if (c == 'I')
        return 1;
    if (c == 'V')
        return 5;
    if (c == 'X')
        return 10;
    if (c == 'L')
        return 50;
    if (c == 'C')
        return 100;
    if (c == 'D')
        return 500;
    if (c == 'M')
        return 1000;
    else
        return 0;
}
