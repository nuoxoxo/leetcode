class Solution {
public:
    int maxWidthRamp(vector<int>& nums)
    {
        deque<int>  dq;
        int         n = (int) nums.size();
        int         res = 0;
        int         i;
        
        i = -1;
        while (++i < n)
        {
            if (dq.empty() || nums[i] < nums[dq.front()])
            {
                dq.push_front(i);
            }
        }
        i = n;
        while (--i > -1)
        {
            while (!dq.empty() && nums[i] >= nums[dq.front()])
            {
                res = max(res, i - dq.front());
                dq.pop_front();
            }
        }
        return res;
    }
};
