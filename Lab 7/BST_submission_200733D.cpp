#include <iostream>
using namespace std;

//Creating the node structure
struct node {
  int key;
  struct node *left; 
  struct node *right;
};

//Function to create a node
struct node *createNode(int val) {
   struct node *temp =  (struct node *)malloc(sizeof(struct node));
   temp->key = val;
   temp->left = temp->right = NULL;
   return temp;
}

// Inorder traversal
void traverseInOrder(struct node *root) {
    
  if (root != NULL) {
      
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);
  }
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
    
  // If the tree is empty, create a new node as the root
  if (node == NULL) 
    return createNode(key);
 
  // Otherwise, recur down the tree
  
  if (key < node->key) {
      
    node->left = insertNode(node->left, key);
  } else if (key > node->key) {
    node->right = insertNode(node->right, key);
  }

  // Return the unchanged node pointer
  return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  // Base case: checking whether the tree is empty
  if (root == NULL) {
    return root;
  }

  // Otherwise, recur down the tree
  if (key < root->key) {
      
    root->left = deleteNode(root->left, key);
  } else if (key > root->key) {
      
    root->right = deleteNode(root->right, key);
    
  } else { // If the key matches with the root
  
    // Case 1: If the node has no children
    if (root->left == NULL && root->right == NULL) {
      delete root;
      root = NULL;
    }
    
    // Case 2: If the node has one child
    else if (root->left == NULL) {
      struct node *temp = root;
      root = root->right;
      delete temp;
    } else if (root->right == NULL) {
      struct node *temp = root;
      root = root->left;
      delete temp;
    }
    
    // Case 3: If the node has two children
    else {
      struct node *temp = root->right;
      while (temp->left != NULL) {
        temp = temp->left;
      }
      root->key = temp->key;
      root->right = deleteNode(root->right, temp->key);
    }
  }

  // Return the unchanged node pointer
  return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}
