class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries)
    {
        int n = (int) nums.size();
        int m = (int) queries.size();
        int prefix = 0;
        int i;

        vector<int> res(m, 0);
        vector<int> p;

        sort(nums.begin(), nums.end());
        i = -1;
        while (++i < n)
        {
            prefix += nums[i];
            p.push_back(prefix);
        }
        i = -1;
        while (++i < m)
        {
            int j = -1;
            int tmp = 0;
            while (++j < n)
            {
                if (p[j] > queries[i])
                    break ;
                ++tmp;
            }
            res[i] = tmp;
        }
        return res ;
    }
};
