class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d)
    {
        int len1 = arr1.size(), len2 = arr2.size();
        int res = 0, i = -1, j, boo;
        while (++i < len1)
        {
            j = -1;
            boo = 1;
            while (++j < len2)
            {
                
                if (abs(arr1[i] - arr2[j]) <= d)
                {
                    boo = 0;
                    break;
                }
            }
            res += boo ;
        }
        return res ;
    }
};
