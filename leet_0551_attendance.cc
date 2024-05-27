class Solution {
public:
    bool checkRecord(string s)
    {
        int A = 0;
        int consecL = 0;
        int L = 0;
        for (char c: s)
        {
            A = c == 'A' ? A + 1 : A;
            if (c == 'L')
            {
                consecL++;
            }
            else
            {
                consecL = 0;
            }
            L = max(L, consecL);
        }
        return A < 2 && L < 3;
    }
};
