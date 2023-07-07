type MapSum struct {
    mp map[string]int
}


func Constructor() MapSum {
    return MapSum {
        // this.mp: make(map[string]int),
        mp: make(map[string]int),
    }
}


func (this *MapSum) Insert(key string, val int)  {
    this.mp[key] = val
}


func (this *MapSum) Sum(prefix string) int {
    res := 0
    for k, v := range this.mp {
        if strings.HasPrefix(k, prefix) {
            res += v
        }
    }
    return res
}


/**
 * Your MapSum object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(key,val);
 * param_2 := obj.Sum(prefix);
 */
