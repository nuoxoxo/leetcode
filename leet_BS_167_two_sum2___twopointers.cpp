class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target)
    {
        int j = (int) n.size() - 1;
        if (j == 1)
            return {1, 2};
        int i = 0;
        while (i < j)
        {
            int t = n[i] + n[j];
            if (t > target)
                --j;
            else if (t < target)
                ++i;
            else
                break;
        }
        return {i + 1, j + 1};
    }
};
