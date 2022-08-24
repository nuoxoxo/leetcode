class Solution {
public:
    string intToRoman(int n) {
        vector<int>     vn = {1, 4, 5, 9, 10, 40, 50, 90,
                              100, 400, 500, 900, 1000};
        vector<string>  vs = {"I","IV","V","IX", "X","XL","L","XC",
                              "C","CD","D","CM", "M"};

        int             i = 12, tmp;
        string          r;

        while (n)
        {
            tmp = n / vn[i];
            n %= vn[i];
            while (tmp--)
                r += vs[i];
            i--;
        }
        return r;
    }
};
