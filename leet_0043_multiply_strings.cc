class Solution {
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";

        int len1 = num1.length();
        int len2 = num2.length();
        int i = len1;
        vector<int> p(len1 + len2, 0);
        string  res;

        while (--i > -1)
        {
            int j = len2;
            while (--j > -1)
            {
                int L = i + j;
                int R = i + j + 1;
                int tmp = (num1[i] - '0') * (num2[j] - '0') + p[R];
                p[L] = tmp / 10 + p[L];
                p[R] = tmp % 10;
            }
        }
        i = 0;
        while (p[i] == 0)
            i++;
        while (i < len1 + len2)
        {
            res += to_string(p[i]);
            ++i;
        }
        return res;
    }
};

/*

"123456789"
"987654321"
"999"
"999"
"2"
"3"
"123"
"456"

*/
