struct MyHashMap {
    K: Vec<i32>,
    V: Vec<i32>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyHashMap {

    fn new() -> Self {
        Self {
            K: Vec::new(),
            V: Vec::new(),
        }
    }
    
    fn put(&mut self, key: i32, value: i32) { // changes &self -> &mut self

        if let Some(idx) = self.K.iter().position( | &k | k == key) {
            self.V[idx] = value;
            return;
        }
        self.K.push(key);
        self.V.push(value);
    }
    
    fn get(&self, key: i32) -> i32 {

        if let Some(idx) = self.K.iter().position( | &k | k == key) {
            self.V[idx]
        } else {
            -1
        }
    }
    
    fn remove(&mut self, key: i32) { // changes &self -> &mut self

        if let Some(idx) = self.K.iter().position( | &k | k == key) {
            self.K.remove(idx);
            self.V.remove(idx);
        }
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * let obj = MyHashMap::new();
 * obj.put(key, value);
 * let ret_2: i32 = obj.get(key);
 * obj.remove(key);
 */
