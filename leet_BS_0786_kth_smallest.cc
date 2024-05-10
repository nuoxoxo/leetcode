class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k)
    {
        int N = arr.size();
        double L = 0.0;
        double R = 1.0;
        while (L < R)
        {
            double maxf = 0.0;
            double mid = L / 2 + R / 2;
            // double I, J; // res -> [L, R]
            int I = 0, J = 0;
            int Kth = 0;
            int j = 0;
            int i = -1;
            while (++i < N - 1)
            {
                while (j < N && arr[i] > arr[j] * mid)
                    ++j;
                Kth += N - j;
                if (j == N)
                    break ;
                if (maxf < (double) arr[i] / (double) arr[j])
                {
                    I = arr[i];
                    J = arr[j];
                    assert (arr[j]);
                    maxf = (double) arr[i] / (double) arr[j];
                }
            }
            if (Kth == k)
                return { I, J };
            if (Kth < k)
                L = mid;
            else
                R = mid;
        }
        return {};
    }
};
