// ===============================
// Binary Tree Node
// ===============================
class TreeNode {
    constructor(val) {
      this.val = val;
      this.left = null;
      this.right = null;
    }
  }
  
  // ===============================
  // 1. Level Order Traversal
  // ===============================
  function levelOrder(root) {
    if (!root) return [];
    let res = [], q = [root];
  
    while (q.length) {
      let size = q.length, level = [];
      for (let i = 0; i < size; i++) {
        let node = q.shift();
        level.push(node.val);
        if (node.left) q.push(node.left);
        if (node.right) q.push(node.right);
      }
      res.push(level);
    }
    return res;
  }
  
  // ===============================
  // 2. Zigzag Level Order
  // ===============================
  function zigzagLevelOrder(root) {
    if (!root) return [];
    let res = [], q = [root], dir = true;
  
    while (q.length) {
      let size = q.length, level = [];
      for (let i = 0; i < size; i++) {
        let node = q.shift();
        dir ? level.push(node.val) : level.unshift(node.val);
        if (node.left) q.push(node.left);
        if (node.right) q.push(node.right);
      }
      dir = !dir;
      res.push(level);
    }
    return res;
  }
  
  // ===============================
  // 3. Diameter of Binary Tree
  // ===============================
  function diameterOfBinaryTree(root) {
    let dia = 0;
  
    function height(node) {
      if (!node) return 0;
      let l = height(node.left);
      let r = height(node.right);
      dia = Math.max(dia, l + r);
      return 1 + Math.max(l, r);
    }
  
    height(root);
    return dia;
  }
  
  // ===============================
  // 4. Check Balanced Binary Tree
  // ===============================
  function isBalanced(root) {
    function dfs(node) {
      if (!node) return 0;
      let l = dfs(node.left);
      if (l === -1) return -1;
      let r = dfs(node.right);
      if (r === -1) return -1;
      if (Math.abs(l - r) > 1) return -1;
      return 1 + Math.max(l, r);
    }
    return dfs(root) !== -1;
  }
  
  // ===============================
  // 5. Lowest Common Ancestor
  // ===============================
  function lowestCommonAncestor(root, p, q) {
    if (!root || root === p || root === q) return root;
    let l = lowestCommonAncestor(root.left, p, q);
    let r = lowestCommonAncestor(root.right, p, q);
    if (l && r) return root;
    return l || r;
  }
  
  // ===============================
  // 6. Path Sum (Root to Leaf)
  // ===============================
  function hasPathSum(root, sum) {
    if (!root) return false;
    if (!root.left && !root.right) return sum === root.val;
    return hasPathSum(root.left, sum - root.val) ||
           hasPathSum(root.right, sum - root.val);
  }
  
  // ===============================
  // 7. Right View of Binary Tree
  // ===============================
  function rightSideView(root) {
    if (!root) return [];
    let res = [], q = [root];
  
    while (q.length) {
      let size = q.length;
      for (let i = 0; i < size; i++) {
        let node = q.shift();
        if (i === size - 1) res.push(node.val);
        if (node.left) q.push(node.left);
        if (node.right) q.push(node.right);
      }
    }
    return res;
  }
  
  // ===============================
  // 8. Vertical Order Traversal
  // ===============================
  function verticalTraversal(root) {
    if (!root) return [];
    let map = new Map();
    let q = [[root, 0]];
  
    while (q.length) {
      let [node, col] = q.shift();
      if (!map.has(col)) map.set(col, []);
      map.get(col).push(node.val);
      if (node.left) q.push([node.left, col - 1]);
      if (node.right) q.push([node.right, col + 1]);
    }
  
    return [...map.entries()]
      .sort((a, b) => a[0] - b[0])
      .map(e => e[1]);
  }
  
  // ===============================
  // 9. Maximum Path Sum
  // ===============================
  function maxPathSum(root) {
    let max = -Infinity;
  
    function dfs(node) {
      if (!node) return 0;
      let l = Math.max(0, dfs(node.left));
      let r = Math.max(0, dfs(node.right));
      max = Math.max(max, node.val + l + r);
      return node.val + Math.max(l, r);
    }
  
    dfs(root);
    return max;
  }
  
  // ===============================
  // 10. Serialize & Deserialize
  // ===============================
  function serialize(root) {
    let res = [];
    function dfs(node) {
      if (!node) {
        res.push("null");
        return;
      }
      res.push(node.val);
      dfs(node.left);
      dfs(node.right);
    }
    dfs(root);
    return res.join(",");
  }
  
  function deserialize(data) {
    let arr = data.split(",");
    let idx = 0;
  
    function dfs() {
      if (arr[idx] === "null") {
        idx++;
        return null;
      }
      let node = new TreeNode(Number(arr[idx++]));
      node.left = dfs();
      node.right = dfs();
      return node;
    }
    return dfs();
  }
  
  // ===============================
  // SAMPLE TREE
  // ===============================
  /*
          1
         / \
        2   3
       / \   \
      4   5   6
  */
  
  let root = new TreeNode(1);
  root.left = new TreeNode(2);
  root.right = new TreeNode(3);
  root.left.left = new TreeNode(4);
  root.left.right = new TreeNode(5);
  root.right.right = new TreeNode(6);
  
  // ===============================
  // TESTING
  // ===============================
  console.log("Level Order:", levelOrder(root));
  console.log("Zigzag:", zigzagLevelOrder(root));
  console.log("Diameter:", diameterOfBinaryTree(root));
  console.log("Balanced:", isBalanced(root));
  console.log("Right View:", rightSideView(root));
  console.log("Vertical:", verticalTraversal(root));
  console.log("Max Path Sum:", maxPathSum(root));
  
  let data = serialize(root);
  console.log("Serialized:", data);
  let newRoot = deserialize(data);
  console.log("Deserialized Level Order:", levelOrder(newRoot));
  