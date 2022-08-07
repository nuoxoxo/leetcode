class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr)
    {
        int n = arr.size();
        int L = 0, R = n - 1;
        while (L <= R)
        {
            int mid = (R - L + 1) / 2 + L;
            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
                return mid;
            if (arr[mid] < arr[mid + 1])
                L = mid + 1;
            else
                R = mid - 1;
        }
        return L;
    }
};
