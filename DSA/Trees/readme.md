
# Binary Trees: A Comprehensive Guide

## Introduction to Binary Trees
A binary tree is a hierarchical data structure where each node has at most two children, typically referred to as the left and right child.

```
    A    <- root
   / \
  B   C  <- children
 / \
D   E    <- leaf nodes
```

## Basic Terminology

- **Root**: The topmost node of the tree (node A in example above)
- **Leaf**: A node with no children (nodes D, E, C in example above)
- **Children**: Direct descendants of a node (B and C are children of A)
- **Subtree**: A tree formed by a node and all its descendants (B, D, E form a subtree)
- **Ancestor**: Any node on the path from root to a given node (A is an ancestor of D)
- **Parent**: Direct ancestor of a node (B is parent of D and E)
- **Sibling**: Nodes that share the same parent (B and C are siblings)
- **Height**: Length of longest path from root to any leaf
- **Depth/Level**: Length of path from root to a specific node

## Types of Binary Trees

### 1. Full Binary Tree
Every node has either 0 or 2 children (no node has exactly 1 child).

**Example**:
```
    1
   / \
  2   3
 / \
4   5
```

**Properties**:
- If a full binary tree has n leaves, it has (2n-1) total nodes
- If a full binary tree has n internal nodes, it has (n+1) leaf nodes

### 2. Complete Binary Tree
- All levels are completely filled except possibly the last level
- The last level has all nodes positioned as left as possible

**Example**:
```
    1
   / \
  2   3
 / \ /
4  5 6
```

**Properties**:
- Used in heap implementation
- Most efficient for array representation
- For n nodes, height is ⌊log₂(n)⌋

### 3. Perfect Binary Tree
All leaf nodes are at the same level, and every internal node has exactly 2 children.

**Example**:
```
    1
   / \
  2   3
 / \ / \
4  5 6  7
```

**Properties**:
- A perfect binary tree of height h has 2^(h+1) - 1 nodes
- Number of leaf nodes = 2^h where h is height
- Perfectly symmetrical structure

### 4. Balanced Binary Tree
Height is at most O(log n), where n is the number of nodes.

**Example**:
```
    1
   / \
  2   3
 / \   \
4   5   6
```

**Properties**:
- Ensures O(log n) time complexity for operations
- Common implementations: AVL trees, Red-Black trees
- Height difference between left and right subtrees is typically limited

### 5. Degenerate/Skewed Binary Tree
Every parent node has only one child, essentially becoming a linked list.

**Example**:
```
    1
     \
      2
       \
        3
         \
          4
```

**Properties**:
- Worst-case scenario for binary trees
- Operations degrade to O(n) time complexity
- Can be right-skewed or left-skewed

## Binary Tree Traversals

### Depth-First Traversals
Using the tree:
```
    1
   / \
  2   3
 / \ / 
4  5 6  
```

- **Inorder** (Left, Root, Right): `4, 2, 5, 1, 6, 3`
- **Preorder** (Root, Left, Right): `1, 2, 4, 5, 3, 6`
- **Postorder** (Left, Right, Root): `4, 5, 2, 6, 3, 1`

### Breadth-First Traversal
- **Level Order**: `1, 2, 3, 4, 5, 6`

## Implementation in C++

### Basic Node Structure
```cpp
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
```

### Creating a Tree
```cpp
TreeNode* createTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    return root;
}
```

### Traversal Implementation
```cpp
// Inorder traversal
void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Level order traversal
void levelOrder(TreeNode* root) {
    if (root == nullptr) return;
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* node = q.front();
        cout << node->data << " ";
        q.pop();
        
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}
```

## Applications of Binary Trees
- Binary Search Trees for efficient searching
- Expression evaluation
- Huffman coding for data compression
- Priority queues using heaps
- Syntax trees in compilers
- Decision trees in machine learning