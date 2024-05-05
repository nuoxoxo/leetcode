int cmp(const void *, const void *);

int numRescueBoats(int* people, int peopleSize, int limit) {
    qsort(people, peopleSize, sizeof(int), cmp );
    int res = 0;
    int l = 0;
    int r = peopleSize - 1;
    while (l <= r)
    {
        if (people[l] + people[r] <= limit)
        {
            l++;
        }
        r--;
        res++;
    }
    return res;
}

int cmp( const void* L, const void* R)
{
    int a = * (int*) L;
    int b = * (int*) R;
    if ( a == b )
        return 0;
    else if ( a < b )
        return -1;
    return 1;
}

