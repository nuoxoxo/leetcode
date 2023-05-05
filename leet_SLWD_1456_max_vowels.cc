class Solution {
public:
    int maxVowels(string s, int k) {
        string  v = "aeiou";
        int L = 0, R = -1;
        int tmp = 0;
        int res = 0;

        while (++R < s.length())
        {
            if (v.find(s[R]) != string::npos)
                ++tmp;
            if (R - L == k)
            {
                if (v.find(s[L]) != string::npos)
                    --tmp;
                L += 1;
            }
            res = res > tmp ? res : tmp;
        }
        return res ;
    }
};
