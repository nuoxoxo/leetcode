class Solution {
public:
    string addStrings(string num1, string num2)
    {
        vector<int> v;
        string      res;
        int         len1 = num1.length();
        int         len2 = num2.length();
        int         diff = abs(len1 - len2);
        int         len = max(len1, len2);
        int         carry, i;

        if (len1 < len2)
            num1 = string(diff, '0').append(num1);
        else
            num2 = string(diff, '0').append(num2);
        i = len;
        while (--i > - 1)
            v.push_back(num1[i] - '0' + num2[i] - '0');       
        i = -1;
        while (++i < v.size())
        {
            if (v[i] > 9)
            {
                carry = v[i] / 10 ;
                if (i < v.size() - 1)
                    v[i + 1] += carry;
                else
                    v.push_back(carry);
                v[i] %= 10;
            }
        }
        for (char c: v)
            res += c + '0';
        reverse(res.begin(), res.end());
        return res;
    }

    // void print(vector<int> d)
    // {
    //     for (int n: d)  cout << n << ' ';
    //     cout << endl;
    // }
};
