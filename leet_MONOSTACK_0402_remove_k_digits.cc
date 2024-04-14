class Solution {
public:
    string removeKdigits(string num, int k)
    {

        cout << "Solution/ Monotonic stack \n";

        int N = num.size();
        if (k >= N)
            return "0";
        vector<char> monostack;
        for (char c: num)
        {
            while (!monostack.empty() && monostack[monostack.size() - 1] > c && k)
            {
                monostack.pop_back();
                k--;
            }
            monostack.push_back(c);
        }
        while (!monostack.empty() && k)
        {
            monostack.pop_back();
            k--;
        }
        if (monostack.empty())
            return "0";
        int left0 = 0;
        while (left0 < monostack.size() && monostack[left0] == '0' && ++left0) ;;
        string res;
        int i = left0 - 1;
        while (++i < monostack.size())
            res += monostack[i];
        if (res == "")
            return "0";
        return res;
    }
};
