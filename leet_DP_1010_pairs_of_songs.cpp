class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) 
    {
        int count, i, DP[60] = {};

        i = -1;
        while ( ++i < time.size() ) DP[time[i] % 60]++;
        count = i = 0;
        while ( ++i < 60 / 2 )  count += DP[60 - i] * DP[i];
        count += DP[30] * (DP[30] - 1) / 2;
        count += DP[0] * (DP[0] - 1) / 2;

        return (count);
    }
};
