class Solution {
public:
    vector<int> sortArray(vector<int>& arr)
    {
        function<void(int, int)>    quicksort = [&](int L, int R)
        {
            if (L >= R)
                return ;

            int     i = L;
            int     j = R;
            int     piv = L + rand() % (R - L + 1);
            int     val = arr[piv];
            int     tmp;

            while (i <= j)
            {
                while (arr[i] < val)
                {
                    ++i;
                }
                while (arr[j] > val)
                {
                    --j;
                }
                if (i <= j)
                {
                    swap(arr[i++], arr[j--]);
                }
            }
            quicksort(L, j);
            quicksort(i, R);
        };
        quicksort(0, arr.size() - 1);
        return arr;
    }
};
