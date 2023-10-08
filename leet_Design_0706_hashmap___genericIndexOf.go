type MyHashMap struct {

    keys []int
    vals []int
}

func Constructor() MyHashMap {

    return MyHashMap {

        keys: []int {},
        vals: []int {},
    }
}

func (this *MyHashMap) Put(key int, value int) {

    idx := this.indexOf(key)
    if idx == -1 {

        this.keys = append(this.keys, key)
        this.vals = append(this.vals, value)
        return
    }
    this.vals[idx] = value
}

func (this *MyHashMap) Get(key int) int {

    idx := this.indexOf(key)
    if idx == -1 {
        return -1
    }
    return this.vals[idx]
}

func (this *MyHashMap) Remove(key int) {

    idx := this.indexOf(key)
    if idx == -1 {
        return
    }
    this.keys = append(this.keys[:idx], this.keys[idx + 1:] ...)
    this.vals = append(this.vals[:idx], this.vals[idx + 1:] ...)
}

func (this *MyHashMap) indexOf(key int) int {
    for i, k := range this.keys {
        if k == key {
            return i
        }
    }
    return -1
}


/**
 * Your MyHashMap object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Put(key,value);
 * param_2 := obj.Get(key);
 * obj.Remove(key);
 */
