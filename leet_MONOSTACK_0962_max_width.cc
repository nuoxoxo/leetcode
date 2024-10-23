class Solution {
public:
    int maxWidthRamp(vector<int>& nums)
    {
        std::deque<int> Q;
        int N = nums.size();
        int i = -1;
        while (++i < N)
            if (Q.empty() || nums[Q.front()] > nums[i])
                Q.push_front(i);
        i = N;
        int res = 0;
        while (--i > -1)
        {
            while ( ! Q.empty() && nums[Q.front()] <= nums[i])
            {
                res = max(res, i - Q.front());
                Q.pop_front();
            }
        }
        return res;
    }
};
