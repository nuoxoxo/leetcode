class Solution {
public:
    int countOdds(int low, int high)
    {
        int diff = high - low;
        if (high % 2 || low % 2)
            return 1 + diff / 2;
        return diff / 2;
    }
};
