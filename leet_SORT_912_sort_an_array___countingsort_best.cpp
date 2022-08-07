class Solution {
public:
    vector<int> sortArray(vector<int>& nums)
    {
        pair<vector<int>::iterator, vector<int>::iterator>  minmax;
        int     index, range, min, max, len, n, i;

        minmax = minmax_element(nums.begin(), nums.end());
        min = *(minmax.first);
        max = *(minmax.second);
        range = max - min + 1;
        len = (int) nums.size();

        vector<int>     count(range);
        vector<int>     res(len);

        for (int n : nums)
        {
            count[n - min] += 1;
        }
        i = 0;
        while (++i < range)
        {
            count[i] += count[i - 1];
        }
        i = len;
        while (--i > -1)
        {
            n = nums[i] - min;
            res[count[n] - 1] = nums[i];
            count[n] -= 1;
        }
        return res;
    }
};
