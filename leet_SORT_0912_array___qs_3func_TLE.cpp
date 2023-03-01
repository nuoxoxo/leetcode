class Solution {
public:
    vector<int> sortArray(vector<int>& nums)
    {
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }
    
    int partition(vector<int>& arr, int low, int high)
    {
        int key = arr[high];
        int i = low;
        int j = low - 1;
        int tmp;
        while (++j <= high)
        {
            if (key >= arr[j])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                ++i;
            }
        }
        return i - 1;
    }
 
    void    quicksort(vector<int>& arr, int low, int high)
    {
        if (low < high)
        {
            int pivot = partition(arr, low, high);
            quicksort(arr, low, pivot - 1);
            quicksort(arr, pivot + 1, high);
        }
    } 
};
