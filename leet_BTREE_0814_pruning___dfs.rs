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
    pub fn prune_tree(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>>
    {
        match root {
            None => None,
            Some(node) => {
                let mut node_ref = node.borrow_mut();
                node_ref.left = Self::prune_tree(node_ref.left.take());
                node_ref.right = Self::prune_tree(node_ref.right.take());
                if node_ref.val == 0 && node_ref.left.is_none() && node_ref.right.is_none() {
                    None
                } else {
                    drop(node_ref);
                    Some(node)
                }
            }
        }
    }
}
