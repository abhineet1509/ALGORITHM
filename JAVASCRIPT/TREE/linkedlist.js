class TreeNode {
    constructor(val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

class LinkedBinaryTree {
    constructor() {
        this.root = null;
    }

    insert(val) { // level-order insertion
        let node = new TreeNode(val);
        if (!this.root) {
            this.root = node;
            return;
        }
        let q = [this.root];
        while (q.length) {
            let curr = q.shift();
            if (!curr.left) {
                curr.left = node;
                return;
            } else q.push(curr.left);

            if (!curr.right) {
                curr.right = node;
                return;
            } else q.push(curr.right);
        }
    }

    inorder(node = this.root) {
        if (!node) return [];
        return [...this.inorder(node.left), node.val, ...this.inorder(node.right)];
    }

    preorder(node = this.root) {
        if (!node) return [];
        return [node.val, ...this.preorder(node.left), ...this.preorder(node.right)];
    }

    postorder(node = this.root) {
        if (!node) return [];
        return [...this.postorder(node.left), ...this.postorder(node.right), node.val];
    }

    levelOrder() {
        let res = [];
        if (!this.root) return res;
        let q = [this.root];
        while (q.length) {
            let curr = q.shift();
            res.push(curr.val);
            if (curr.left) q.push(curr.left);
            if (curr.right) q.push(curr.right);
        }
        return res;
    }
}

// Test
let linkedTree = new LinkedBinaryTree();
linkedTree.insert(1);
linkedTree.insert(2);
linkedTree.insert(3);
linkedTree.insert(4);
linkedTree.insert(5);

console.log("LinkedTree Inorder:", linkedTree.inorder());
console.log("LinkedTree Preorder:", linkedTree.preorder());
console.log("LinkedTree Postorder:", linkedTree.postorder());
console.log("LinkedTree LevelOrder:", linkedTree.levelOrder());
