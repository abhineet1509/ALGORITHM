class QueueNode {
    constructor(val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

class QueueBinaryTree {
    constructor() {
        this.root = null;
    }

    insert(val) {
        let node = new QueueNode(val);
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
let queueTree = new QueueBinaryTree();
queueTree.insert(1);
queueTree.insert(2);
queueTree.insert(3);
queueTree.insert(4);
queueTree.insert(5);

console.log("QueueTree Inorder:", queueTree.inorder());
console.log("QueueTree Preorder:", queueTree.preorder());
console.log("QueueTree Postorder:", queueTree.postorder());
console.log("QueueTree LevelOrder:", queueTree.levelOrder());
