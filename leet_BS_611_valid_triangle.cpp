class Solution {
public:
    int triangleNumber(vector<int>& nums)
    {
        int s1 = (int) nums.size();
        int s2, s3, count = 0;
        sort(nums.begin(), nums.end());
        while (--s1 > 1)
        {
            s2 = 0, s3 = s1 - 1;
            while (s2 < s3)
            {
                if (nums[s2] + nums[s3] > nums[s1])
                {
                    count += s3 - s2;
                    --s3;
                }
                else
                    ++s2;
            }
        }
        return count ;
    }
};
