class Solution {
public:
    int subtractProductAndSum(int n)
    {
        int o, p=1, s=0;
        while (n) o=n%10, p*=o, s+=o, n/=10;
        return p-s;
    }
};
