impl Solution {
    pub fn unique_occurrences(arr: Vec<i32>) -> bool
    {
        use std::collections::{ HashMap, HashSet };

        let mut map: HashMap<i32, i32> = HashMap::new();
        let mut set: HashSet<i32> = HashSet::new();

        for &n in arr.iter()
        {
            let it = map.entry(n).or_insert(0);
            *it += 1;
        }
        
        for (_, &n) in &map
        {
            set.insert(n);
        }

        map.len() == set.len()
    }
}
