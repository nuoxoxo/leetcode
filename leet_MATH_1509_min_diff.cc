class Solution {
/*
lets say we got: 5,3,2,4,1,5,0,10,14
1) sort it 
2) we have 3 moves, the only possible choices are:

0, 1, 2, 3, 4, 5, 5, 10, 14
^  ^  ^  _               __ -- change these 3, then no matter what we will do,
3, 3, 3, 3, 4, 5, 5, 10, 14 -- 3 ie. nums[3] will be the MIN and 14 ie. nums[N-1] will be MAX


0, 1, 2, 3, 4, 5, 5, 10, 14
^  ^  _              __   ^ -- what if we edit from the right, we can reduce it to next MAX  
2, 2, 2, 3, 4, 5, 5, 10, 10 -- MIN: 2, ie. nums[2], MAX: 10, ie. nums[N-2]


0, 1, 2, 3, 4, 5, 5, 10, 14
^  _              _   ^   ^ -- we have 1, 5 which are nums[1], nums[N - 3]
1, 1, 2, 3, 4, 5, 5,  5,  5 -- which yields 4


0, 1, 2, 3, 4, 5, 5, 10, 14
_              _  ^   ^   ^ -- we have 0, 5 which are nums[0], nums[N - 4]
0, 1, 2, 3, 4, 5, 5,  5,  5 -- also yields 4
*/
public:
    int minDifference(vector<int>& nums)
    {
        vector<int(*)(vector<int> &)> solutions = {
            bruteforce,
        };
        return solutions[0](nums);
    }

    static int bruteforce(vector<int> & nums)
    {
        int N = (int) nums.size();
        if (N < 5)
            return 0;
        sort(begin(nums), end(nums));
        int i = -1;
        long long res = LLONG_MAX;
        while (++i < 4)
        {
            if (res > nums[N - 4 + i] - nums[i])
                res = nums[N - 4 + i] - nums[i];
        }
        return (int)res;
    }
};
