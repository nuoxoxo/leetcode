class Solution {
public:

    /*
    N = 5, K = 2
      1
    5   2
     4 3

     
    */
    int findTheWinner(int n, int k)
    {
        std::function<int(int,int)> f = [&](int N, int K) {
            if (N == 1)
                return 0;
            int res = f(N - 1, K) + K;
            return res % N;
        };
        return f(n, k) + 1;
    }
};
