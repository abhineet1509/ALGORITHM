# Node class
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Recursive insertion (insert in first available position, level-wise)
def insert(root, data):
    if root is None:
        return Node(data)

    
    if root.left is None:
        root.left = Node(data)
    
    elif root.right is None:
        root.right = Node(data)
    # Else, try inserting recursively in left subtree
    else:
        root.left = insert(root.left, data)
    return root

# Recursive Traversals
def inorder(root):
    if root:
        inorder(root.left)
        print(root.data, end=' ')
        inorder(root.right)

def preorder(root):
    if root:
        print(root.data, end=' ')
        preorder(root.left)
        preorder(root.right)

def postorder(root):
    if root:
        postorder(root.left)
        postorder(root.right)
        print(root.data, end=' ')

# -----------------------
# Main Program
# -----------------------
if __name__ == "__main__":
    values = [1, 2, 3, 4, 5, 6, 7]
    root = None

    # Insert nodes recursively
    for val in values:
        root = insert(root, val)

    # Display traversals
    print("Inorder Traversal:")
    inorder(root)
    print("\nPreorder Traversal:")
    preorder(root)
    print("\nPostorder Traversal:")
    postorder(root)
