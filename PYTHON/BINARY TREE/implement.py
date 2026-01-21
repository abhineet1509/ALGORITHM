from collections import deque

# -------------------------------
# Node class (linked list style)
# -------------------------------
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# -------------------------------
# Build Binary Tree Level-wise
# -------------------------------
def build_tree_levelwise(values):
    """
    Build a binary tree from a list of values (level order)
    Use None for empty nodes
    """
    if not values:
        return None

    iter_vals = iter(values)
    root = Node(next(iter_vals))
    queue = deque([root])

    for val in iter_vals:
        parent = queue[0]  # peek front

        if not parent.left:
            if val is not None:
                parent.left = Node(val)
                queue.append(parent.left)
        elif not parent.right:
            if val is not None:
                parent.right = Node(val)
                queue.append(parent.right)
            queue.popleft()  # remove node after both children processed

    return root

# -------------------------------
# Recursive Traversals
# -------------------------------
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

# -------------------------------
# Main Program
# -------------------------------
if __name__ == "__main__":
    # Level-order input (use None for missing nodes)
    values = [1, 2, 3, 4, 5, None, 6]

    # Build tree
    root = build_tree_levelwise(values)

    # Display traversals
    print("Inorder Traversal:")
    inorder(root)
    print("\nPreorder Traversal:")
    preorder(root)
    print("\nPostorder Traversal:")
    postorder(root)
