// To run this, install prompt-sync: npm install prompt-sync
const prompt = require('prompt-sync')({sigint: true});

class Node {
    constructor(val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

// Recursive tree creation like C++ example
function createBinaryTree() {
    let x = parseInt(prompt("Enter node value (-1 for NULL): "));
    if (x === -1) return null;

    let temp = new Node(x);
    console.log(`Enter left child of ${x}:`);
    temp.left = createBinaryTree();
    console.log(`Enter right child of ${x}:`);
    temp.right = createBinaryTree();

    return temp;
}

// Recursive Traversals
function inorder(node) {
    if (!node) return [];
    return [...inorder(node.left), node.val, ...inorder(node.right)];
}

function preorder(node) {
    if (!node) return [];
    return [node.val, ...preorder(node.left), ...preorder(node.right)];
}

function postorder(node) {
    if (!node) return [];
    return [...postorder(node.left), ...postorder(node.right), node.val];
}

// ================= TEST =================
console.log("Create your Binary Tree recursively:");
let root = createBinaryTree();

console.log("Inorder Traversal:", inorder(root));
console.log("Preorder Traversal:", preorder(root));
console.log("Postorder Traversal:", postorder(root));
