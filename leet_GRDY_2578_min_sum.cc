class Solution {
public:
    int splitNum(int num) {
        vector<int(*)(int)> solutions {
            // sorted_string,
            sorted_ints,
        };
        return solutions[0](num);
    }

    static int sorted_ints(int num)
    {
        vector<int> arr;
        while (num)
        {
            int n = num % 10;
            arr.push_back(n);
            num /= 10;
        }
        sort(begin(arr), end(arr));
        int L = 0, R = 0;
        int i = -1;
        while (++i < arr.size())
        {
            int n = arr[i];
            if (i % 2)
                L = L * 10 + n;
            else 
                R = R * 10 + n;
        }
        return L + R;
    }

    static int sorted_string(int num)
    {
        string s = std::to_string(num);
        sort(begin(s), end(s));
        int L = 0, R = 0;
        int i = -1;
        while (++i < s.length())
        {
            int n = s[i] - '0';
            if (i % 2)
                L = L * 10 + n;
            else 
                R = R * 10 + n;
        }
        return L + R;
    }
};
