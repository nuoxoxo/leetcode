class Solution {
public:
    int calculate(string s)
    {
        deque<int>  D;
        int         len, i;
        int         temp, sign, res;

        len = (int) s.length();
        res = 0;
        sign = 1;
        i = -1;
        while (++i < len)
        {
            if (s[i] <= '9' && s[i] >= '0')
            {
                temp = 0;
                while (s[i] <= '9' && s[i] >= '0' && i < len)
                {
                    temp *= 10;
                    temp += s[i] - '0';
                    ++i;
                }
                res += temp * sign;
                --i;
            }
            else if (s[i] == '+')
                sign = 1;
            else if (s[i] == '-')
                sign = -1;
            else if (s[i] == '(')
            {
                D.push_front(res);
                D.push_front(sign);
                res = 0;
                sign = 1;
            }
            else if (s[i] == ')')
            {
                temp = D.front();
                D.pop_front();
                res *= temp;
                temp = D.front();
                D.pop_front();
                res += temp;
            }
        }
        return res;
    }
};
