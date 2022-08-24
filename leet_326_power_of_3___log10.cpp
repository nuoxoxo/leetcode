class Solution {
public:
    bool isPowerOfThree(int n)
    {
        double      r;

        if (!n)
            return false;
        r = log10(n) / log10(3);
        std::cout << log10(n) << ' ' << log10(3) << std::endl;
        std::cout << std::fixed;
        std::cout << std::setprecision(20);
        std::cout << r << std::endl;
        std::cout << ceil(r) << ' ' << floor(r) << std::endl;
        if (ceil(r) == floor(r))
            return true;
        return false;
    }
};
