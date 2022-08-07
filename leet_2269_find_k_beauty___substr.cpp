class Solution {
public:
    int divisorSubstrings(int num, int k)
    {
        string  s = to_string(num);
        int     len = s.length();
        int     i = -1;
        int     c = 0;

        while (++i < len - k + 1)
        {
            int temp = stoi(s.substr(i, k));

            if (temp > 0 && !(num % temp))
                ++c;
        }
        return c;
    }
};
