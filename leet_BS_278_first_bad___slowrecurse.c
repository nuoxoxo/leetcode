// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int FBV(int, int, int, int);

int firstBadVersion(int n){
    return FBV(n, 0, n, n) ;
}

//  "all the versions after a bad version are bad"

int FBV(int n, int L, int R, int first){
    if (R < L)
        return first ;
    int mid = L + (R - L) / 2;
    if (isBadVersion(mid)){
        first = mid;
        return FBV(n, L, first - 1, first) ;
    }
    else
        return FBV(n, mid + 1, R, first) ;
}
