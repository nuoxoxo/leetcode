impl Solution {
    pub fn sort_people(names: Vec<String>, heights: Vec<i32>) -> Vec<String> {

        use std::cmp::Ordering;
        struct NH { n:String, h:i32 }
        let mut nhs : Vec<NH> = names
            .into_iter()//iter()
            .zip(heights.into_iter()/*iter()*/)
            .map( | (n, h) | NH {n, h} )
            .collect();
        nhs.sort_by( | l, r | r.h.cmp(&l.h) );
        nhs.into_iter()/*iter()*/.map( | nh | nh.n ).collect()//;
    }
}
