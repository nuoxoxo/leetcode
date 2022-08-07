class Solution {
public:
    vector<int> sortArray(vector<int>& nums)
    {
        pair<vector<int>::iterator, vector<int>::iterator>  minmax;
        int     index, range, min, max, i;

        minmax = minmax_element(nums.begin(), nums.end());
        min = *(minmax.first);
        max = *(minmax.second);
        range = max - min + 1;

        vector<int>     count(range);

        for (int n: nums)
        {
            count[n - min] += 1;
        }
        i = -1;
        index = 0;
        while (++i < range)
        {
            while (count[i] > 0)
            {
                nums[index++] = min + i;
                count[i] -= 1;
            }
        }
        return nums;
    }
};
