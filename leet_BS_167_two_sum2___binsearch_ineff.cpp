class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int         L, R, i, df, midpoint, midvalue;
        bool        found;
        vector<int> res;

        i = -1;
        while (++i < numbers.size())
        {
            df = target - numbers[i];
            R = numbers.size() - 1;
            L = i + 1;
            found = false;
            while (!(L > R))
            {
                midpoint = L + (R - L) / 2;
                midvalue = numbers[midpoint];
                if (midvalue > df)      R = midpoint - 1;
                else if (midvalue < df) L = midpoint + 1;
                else
                {
                    found = true;
                    break;
                }
            }
            if (!found)         midvalue = -1;
            if (midvalue != -1) break;
        }
        res = {i + 1, midpoint + 1};
        return (res);
    }
};
