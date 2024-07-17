// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn get_directions(root: Option<Rc<RefCell<TreeNode>>>, start_value: i32, dest_value: i32) -> String
    {
        fn find(path: &mut Vec<char>, node: Option<Rc<RefCell<TreeNode>>>, tar: i32) -> bool
        {
            if let Some(n) = node
            {
                let n = n.borrow();
                if n.val == tar {
                    return true;
                }
                if find(path, n.left.clone(), tar)
                {
                    path.push('L');
                    return true;
                }
                if find(path, n.right.clone(), tar)
                {
                    path.push('R');
                    return true;
                }
            }
            false
        }

        let mut up = Vec::new();
        let mut down = Vec::new();

        find(&mut up, root.clone(), start_value);
        find(&mut down, root.clone(), dest_value);

        while !up.is_empty() && !down.is_empty() && up.last() == down.last()
        {
            up.pop();
            down.pop();
        }

        up.reverse();
        down.reverse();
        
        let l: String = "U".repeat(up.len());
        let r: String = down.iter().collect();

        l + &r
    }
}
