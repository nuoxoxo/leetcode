class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
        vector<int> res;
        int n = arr.size();
        int right = n - 1;
        int left = 0;
        while (left < right && n > k)
        {
            if (abs(arr[left] - x) > abs(arr[right] - x))
                ++left;
            else
                --right;
            --n;
        }
        //cout << left << ' ' << right << endl;
        while (left <= right){
            res.push_back(arr[left]);
            left++;
        }
        return res ;
    }
};
