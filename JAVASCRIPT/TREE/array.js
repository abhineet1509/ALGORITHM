class ArrayBinaryTree {
    constructor() {
        this.tree = []; // array representation
    }

    insert(val) {
        this.tree.push(val); // insert at the end
    }

    inorder(index = 0) {
        if (index >= this.tree.length) return [];
        let res = [];
        res.push(...this.inorder(2 * index + 1));
        res.push(this.tree[index]);
        res.push(...this.inorder(2 * index + 2));
        return res;
    }

    preorder(index = 0) {
        if (index >= this.tree.length) return [];
        let res = [];
        res.push(this.tree[index]);
        res.push(...this.preorder(2 * index + 1));
        res.push(...this.preorder(2 * index + 2));
        return res;
    }

    postorder(index = 0) {
        if (index >= this.tree.length) return [];
        let res = [];
        res.push(...this.postorder(2 * index + 1));
        res.push(...this.postorder(2 * index + 2));
        res.push(this.tree[index]);
        return res;
    }
}

// Test
let arrTree = new ArrayBinaryTree();
arrTree.insert(1);
arrTree.insert(2);
arrTree.insert(3);
arrTree.insert(4);
arrTree.insert(5);

console.log("ArrayTree Inorder:", arrTree.inorder());
console.log("ArrayTree Preorder:", arrTree.preorder());
console.log("ArrayTree Postorder:", arrTree.postorder());
