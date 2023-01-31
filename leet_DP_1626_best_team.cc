class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages)
    {
        vector<tuple<int, int>> pairs;
        int i = -1;
        while (++i < ages.size())
            pairs.push_back({scores[i], ages[i]});
        sort(pairs.begin(), pairs.end());
        // for (tuple<int, int> & p: pairs)
        //     cout << get<0>(p) << " " << get<1>(p) << "\n";

        vector<int>     DP;
        // while (++i < pairs.size())
            // DP.push_back(pairs[i][0]);
        for (tuple<int, int> & p: pairs)
            DP.push_back(get<0>(p));

        i = -1;
        while (++i < pairs.size())
        {
            int score = get<0>(pairs[i]);
            int age = get<1>(pairs[i]);
            int j = -1;
            while (++j < i)
            {
                int temp_score = get<0>(pairs[j]);
                int temp_age = get<1>(pairs[j]);
                if (age >= temp_age)
                    DP[i] = max(DP[i], score + DP[j]);
            }
        }
        return *max_element(DP.begin(), DP.end());
    }
};
