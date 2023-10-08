class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score)
    {
        //  way 1 : sorting
        //  (still looking for another way)

        vector<int> sorted = score;
        sort(sorted.begin(), sorted.end(), greater<int>());
        // for (int n: sorted)
        //     cout << n << ' ';
        vector<string>  res;
        for (int n: score)
        {
            int idx = find(sorted.begin(), sorted.end(), n) - sorted.begin();
            switch (idx)
            {
                case 0:
                    res.push_back("Gold Medal");
                    break;
                case 1:
                    res.push_back("Silver Medal");
                    break;
                case 2:
                    res.push_back("Bronze Medal");
                    break;
                default:
                    res.push_back(to_string(idx + 1));
                    break;
            }
        }
        return res;
    }
};
