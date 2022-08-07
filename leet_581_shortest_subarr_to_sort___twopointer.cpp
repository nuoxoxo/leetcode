class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        int n = (int) nums.size();
        if (n < 2)
            return 0;
        int prev = nums[0];
        int head = n - 1;   // find smallest index not in place
        int tail = 0;       // find largest index not in place
        int i = 0; 
        while (++i < n)
        {
            if (prev > nums[i]) // replace temp if unordered
                tail = i;
            else
                prev = nums[i];
        }
        if (!tail)
            return 0;
        prev = nums[n - 1];
        i = n - 1;
        while (--i > -1)
        {
            if (nums[i] > prev)
                head = i;
            else
                prev = nums[i];
        }
        return tail - head + 1;
    }
};

/*
[2,6,4,8,10,9,15]
[1,2,3,4]
[1]
[1,3,2,4,5]
[1,3,2,2,2]
*/
