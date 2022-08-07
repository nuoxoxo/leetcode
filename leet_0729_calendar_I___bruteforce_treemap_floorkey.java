class MyCalendar {

    private TreeMap<Integer, Integer>       mp;

    public MyCalendar()
    {
        mp = new TreeMap<>();
    }
    
    public boolean book(int start, int end)
    {
        Integer     low_key, low, high;

        if (mp.isEmpty())
        {
            mp.put(start, end);
            return true;
        }
        low_key = mp.floorKey(start);
        if (low_key != null)
            low = mp.get(low_key);
        else
            low = 0;
        high = mp.ceilingKey(start);
        if ((low_key == null || low < start + 1) && (high == null || high > end - 1))
        {
            mp.put(start, end);
            return true;
        }
        return false;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */
