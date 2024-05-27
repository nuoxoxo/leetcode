class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges)
    {
        long long tt = 0;
        for (int n: nums)
            tt += n;

        vector<long long > updates;
        for (int n: nums)
            updates.push_back((n ^ k) - n);
        sort(begin(updates), end(updates), std::greater<int>()); 
       
        long long  res = tt;
        int N = nums.size();
        int i = 0;
        while (i < N - 1)
        {
            tt += updates[i] + updates[i + 1];
            res = max(res, tt);
            i += 2;
        }
        return res;
    }
};
