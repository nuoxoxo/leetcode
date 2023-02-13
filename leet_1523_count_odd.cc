class Solution {
public:
    int countOdds(int low, int high)
    {
        int     offset = (high - low) / 2;
        if (low % 2 ^ 0 || high % 2 ^ 0)
            ++offset;
        return offset;
    }
};
