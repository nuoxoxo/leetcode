class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& Q)
    {
        int         len, sum, tmp, val, idx, i;
        vector<int> res;

        len = nums.size();
        sum = 0;
        i = -1;
        while (++i < len)
        {
            if (nums[i] % 2)
                continue ;
            sum += nums[i];
        }
        i = -1;
        while (++i < Q.size())
        {
            val = Q[i][0];
            idx = Q[i][1];
            tmp = nums[idx];
            nums[idx] += val;
            if (tmp % 2 == 0)
            {
                if (nums[idx] % 2)
                    sum -= tmp;
                else
                    sum += val;
            }
            else if (tmp % 2 && ! (nums[idx] % 2))
            {
                sum += nums[idx];
            }
            res.push_back(sum);
        }
        return res;
    }
};
