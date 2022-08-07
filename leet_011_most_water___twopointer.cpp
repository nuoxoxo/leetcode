class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int n = height.size();
        int right = n - 1;
        int left = 0;
        int tmp, res = 0;
        while (left ^ right)
        {
            tmp = (right - left) * min(height[right], height[left]);
            res = max(tmp, res);
            if (height[left] < height[right])
                ++left;
            else
                --right;
        }
        return res ;
    }
};
