class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies)
    {
        int most = *max_element(candies.begin(), candies.end());
        vector<bool>    res;

        for (int n : candies)
        {
            if (n + extraCandies < most)
                res.push_back(false);
            else
                res.push_back(true);
        }
        return res;
    }
};
