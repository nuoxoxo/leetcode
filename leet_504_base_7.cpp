class Solution {
public:
    string convertToBase7(int num) {

        if (!num)   return "0";

        string  s = "";//, res = "";
        long    n = num;
        bool    sign = false;

        if (num < 0)
            n = -n, sign = true;
        while (n)
        {
            s += (char) (n % 7 + '0');
            n /= 7 ;
        }
        return sign ? '-' + string(s.rbegin(), s.rend()) : string(s.rbegin(), s.rend()) ;
    }
};
