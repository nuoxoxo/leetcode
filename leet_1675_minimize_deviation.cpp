class Solution {
public:
    int minimumDeviation(vector<int>& nums)
    {
        priority_queue<int> E;
        int                 res, tmp, n, i;

        i = -1;
        res = tmp = 1e9;
        while (++i < nums.size())
        {
            if (nums[i] % 2)
                nums[i] *= 2;
            tmp = min(tmp, nums[i]);
            E.push(nums[i]);
        }
        while (E.top() % 2 == 0)
        {
            n = E.top();
            E.pop();
            n /= 2;
            tmp = min(tmp, n);
            E.push(n);
            res = min(res, E.top() - tmp);
        }
        return res ;
    }
};
