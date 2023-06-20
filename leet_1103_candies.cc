class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people)
    {
        vector<int> res(num_people, 0);
        int c = 0;
        int idx = 0;
        int n;
        while (++c && candies)
        {
            n = c < candies ? c : candies;
            candies -= n;
            res[idx] += n;
            idx++;
            idx %= num_people;
        }
        return res;

    }
};
