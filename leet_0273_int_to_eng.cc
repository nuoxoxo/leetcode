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

        std::function<string(int)> go = [&](int N){
            string res;
            if (N > 99)
            {
                int hun = N / 100;
                res += U[hun] + " Hundred";
                N %= 100;
                if (!N)
                    return res;
            }
            if (N < 20)
            {
                if (res != "")
                    res += " ";
                res += U[N];
                return res;
            }
            // >= 30
            int n = N / 10;
            if (res != "")
                res += " ";
            res += T[n - 2];
            N %= 10;
            if (N)
            {
                if (res != "")
                    res += " ";
                res += U[N];
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
