class Solution {
public:
    int countTriplets(vector<int>& arr)
    {
        // insight :
        //  a == b -> a ^ b == 0

        //  arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1] == 
        //  arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
        
        // becomes
        //  arr[i] ^ arr[i + 1] ^ ... ^ arr[j] ^ arr[j + 1] ^ ... ^ arr[k] == 0
        // ie.
        //  arr[i] ^ arr[i + 1] ^ ... ^ arr[k] == 0

        int res = 0;
        int prefixXOR = 0;
        map<int, int> f; // prefix XOR: times seen
        f[0] = 1;
        map<int, int> sums; // prefix XOR: sum of indices

        int i = -1;
        int N = arr.size();
        while (++i < N)
        {
            int n = arr[i];
            prefixXOR ^= n;
            if (f.find(prefixXOR) != f.end())
            {
                res += f[prefixXOR] * i - sums[prefixXOR];
                f[prefixXOR]++;
                sums[prefixXOR] += i + 1;
            }
            else
            {
                f[prefixXOR] = 1;
                sums[prefixXOR] = i + 1;
            }
        }
        return res;
    }
};
