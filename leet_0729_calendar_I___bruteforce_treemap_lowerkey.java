class MyCalendar {

    private TreeMap<Integer, Integer>       mp;

    public MyCalendar()
    {
        mp = new TreeMap<>();
    }
    
    public boolean book(int start, int end)
    {
        Integer         key;

        key = mp.lowerKey(start);
        if (key != null && mp.get(key) > start)
            return false;
        key = mp.ceilingKey(start);
        if (key != null && (key == start || key < end))
            return false;
        mp.put(start, end);
        return true;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */
