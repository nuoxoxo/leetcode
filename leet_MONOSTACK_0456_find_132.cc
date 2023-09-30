class Solution {
public:
    bool find132pattern(vector<int>& nums)
    {
        int mid = INT_MIN;
        deque<int>  D;
        int i = (int) nums.size();
        while (--i > -1)
        {
            int L = nums[i];
            if (L < mid)
                return (true);
            while (!D.empty() && D.back() < L)
            {
                mid = D.back();
                D.pop_back();
            }
            D.push_back(L);
        }
        return (false);
    }
};
