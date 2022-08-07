class Solution {
public:
    vector<int> sortArray(vector<int>& arr)
    {
        quicksort(arr, 0, arr.size() - 1);
        return (arr);
    }

    void    quicksort(vector<int>& arr, int L, int R)
    {
        if (L >= R)
	{
		return ;
	}
        int i = L;
        int j = R;
        int p = i + rand() % (j - i + 1);
        int tmp = arr[p];
        arr[p] = arr[i];
        arr[i] = tmp;
        while (i < j)
        {
            while (i < j && tmp <= arr[j])
            {
                --j;
            }
            arr[i] = arr[j];
            while (i < j && tmp >= arr[i])
            {
                ++i;
            }
            arr[j] = arr[i];
        }
        arr[i] = tmp;
        quicksort(arr, L, i - 1);
        quicksort(arr, i + 1, R);
    }
};
