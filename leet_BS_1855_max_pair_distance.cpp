class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2)
    {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int i = -1, res = 0;
        while (++i < len1)
        {
            if (res > len2 - 1 - i)
                break;
            int L = i, R = len2 - 1;
            while (L <= R)
            {
                int mid = (R - L) / 2 + L;
                if (nums1[i] <= nums2[mid])
                {
                    res = max(res, mid - i);
                    L = mid + 1;
                }
                else
                    R = mid - 1;
            }
        }
        return res ;
    }
};
