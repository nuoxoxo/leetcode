class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        vector<vector<int>(*)(vector<int>&)> solutions {
            DP,
        };
        return solutions[0](nums);
    }

    static vector<int> DP (vector<int> & nums)
    {

        int len = nums.size();
        if (len == 0)
            return {};

        vector<vector<int>> DP(len, vector<int>());
        sort(nums.begin(), nums.end());
        int i = -1;
        while (++i < len)
            DP[i].push_back(nums[i]);

        i = -1;
        while (++i < len) {
            int j = -1;
            while (++j < i) {
                if ( nums[i] % nums[j] == 0 && DP[i].size() - 1 < DP[j].size()) {
                    DP[i] = DP[j];
                    DP[i].push_back(nums[i]);
                }
            }
        }

        int max = -1e9;
        int pos = -1;
        i = -1;
        while (++i < len) {
            int N = DP[i].size();
            if (max < N) {
                pos = i;
                max = N;
            }
        }
        return DP[pos];
    }
};
