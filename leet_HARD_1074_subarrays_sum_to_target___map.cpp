class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& grid, int target)
    {
        int     r, c, i, j, k, count;

        r = grid.size();
        if (!r)
            return (0);
        c = grid[0].size();
        count = 0;
        i = -1;
        while (++i < r)
        {
            vector<int>     temp(c, 0);

            j = i + 1;
            while (--j > -1)
            {
                k = -1;
                while (++k < c)
                    temp[k] += grid[j][k];
                count += subarray_sum(temp, target);
            }
        }
        return (count);
    }

    int subarray_sum(vector<int>& arr, int target)
    {
        map<int, int>   mp;
        int             sum;
        int             res, len, i;

        len = arr.size();
        res = 0;
        sum = 0;
        i = -1;
        while (++i < len)
        {
            sum += arr[i];
            if (sum == target)
                ++res;
            if (mp.find(sum - target) != mp.end())
                res += mp[sum - target];
            mp[sum]++;
        }
        return (res);
    }
};
