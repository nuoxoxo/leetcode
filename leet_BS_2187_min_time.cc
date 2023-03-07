class Solution {
public:
    #define ull unsigned long long

    long long minimumTime(vector<int>& time, int totalTrips) {
        ull r = (ull) *min_element(time.begin(), time.end()) * (ull) totalTrips;
        ull l = 0;
        while (l < r)
        {
            ull mid = l + (r - l) / 2;

            if (ok(mid, time, totalTrips))
                r = mid;
            else
                l = mid + 1;
        }
        return (long long) l;
    }

    bool    ok(unsigned long long n, vector<int> & time, int total)
    {
        unsigned long long  trips = 0;
        for (int t: time)
            trips += n / t;
        return (trips >= total);
    }
};;
