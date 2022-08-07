type MyCalendar struct {
    mp [][]int
}


func Constructor() MyCalendar {
    return MyCalendar{}
}


func (this *MyCalendar) Book(start int, end int) bool {
    for _ , p := range this.mp {
        if p[0] < end && p[1] > start {
            return false
        }
    }
    this.mp = append(this.mp, [] int {start, end})
    return true
}


/**
 * Your MyCalendar object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Book(start,end);
 */
