class Solution {
public:
    int maxConsecutiveAnswers(string s /* answerKey */, int k)
    {
        int res = 0;
        int len = s.length();
        int T = 0, F = 0;
        int L = 0;
        int R = -1;

        while (++R < len)
        {
            if (s[R] == 'T')
                ++T;
            else
                ++F;
            while (T > k && F > k)
            {
                if (s[L] == 'T')
                    --T;
                else
                    --F;
                ++L;
            }
            res = max(res, R - L + 1);
        }
        return res;
    }
};
