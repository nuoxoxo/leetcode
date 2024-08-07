class Solution {
public:
    string numberToWords(int num)
    {
        vector<string> U = {
            "Zero", "One", "Two", "Three",
            "Four", "Five", "Six", 
            "Seven", "Eight", "Nine", "Ten", 
            "Eleven", "Twelve", "Thirteen", 
            "Fourteen", "Fifteen", "Sixteen", 
            "Seventeen", "Eighteen", "Nineteen"
        };
        vector<string> T = {
            "Twenty", "Thirty", "Forty", "Fifty",
            "Sixty", "Seventy", "Eighty", "Ninety"
        };
        map<int, string> E;
        E[100] = "Hundred";
        E[1000] = "Thousand";
        E[1000000] = "Million";
        E[1000000000] = "Billion";
        std::function<string(int)> go = [&](int n){
            string res;
            if (n > 99)
            {
                int hun = n / 100;
                res += U[hun] + " Hundred";
                n %= 100;
                if (!n)
                    return res;
            }
            if (n < 20)
            {
                if (res != "")
                    res += " ";
                res += U[n];
                return res;
            }
            // >= 30
            int num = n / 10;
            if (res != "")
                res += " ";
            res += T[num - 2];
            n %= 10;
            if (n)
            {
                if (res != "")
                    res += " ";
                res += U[n];
            }
            return res;
        };

        if (!num)
            return U[num];
        string res, tmp;
        // billion
        if (num / 1000000000)
            res += go(num / 1000000000) + " Billion";
        num %= 1000000000;
        // million
        if (num / 1000000)
        {
            if (res != "")
                res += " ";
            res += go(num / 1000000) + " Million";
        }
        num %= 1000000;
        // 1,000
        if (num / 1000)
        {
            if (res != "")
                res += " ";
            res += go(num / 1000) + " Thousand";
        }
        num %= 1000;
        if (num)
        {
            if (res != "")
                res += " ";
            res += go(num);
        }
        return res;
    }
};
