class Solution {
public:
    int splitNum(int num) {
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
