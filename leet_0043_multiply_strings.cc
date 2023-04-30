class Solution {
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return ("0");

        vector<int> product(num1.size() + num2.size(), 0);
        int         len1 = num1.length();
        int         len2 = num2.length();
        int         L, R, i, j, pairing;
        string      res;
        
        i = len1;
        while (--i > -1)
        {
            j = len2;
            while (--j > -1)
            {
                L = i + j;
                R = i + j + 1;
                pairing = (num1[i] - 48) * (num2[j] - 48) + product[R];
                product[L] = pairing / 10 + product[L];
                product[R] = pairing % 10;
            }
        }
        i = 0;
        while (product[i] == 0)
            i++;
        while (i < len1 + len2)
            res += to_string(product[i++]);

        return (res);
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
