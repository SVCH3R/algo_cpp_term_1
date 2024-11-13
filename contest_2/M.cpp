#include <iostream>

struct Node {
  const int64_t key;
  Node* left = nullptr;
  Node* right = nullptr;
  Node* parent = nullptr;

  explicit Node(const int64_t key) : key(key) {
  }
};

class BinSearchTree {
  Node* root_ = nullptr;
  int64_t height_ = 0;
  int64_t currheight_ = 0;

  void Execute(Node* node) {
    if (node == nullptr) {
      return;
    }
    Execute(node->left);
    Execute(node->right);
    delete node;
    node = nullptr;
  }

  Node* Push(int64_t key, Node* root, Node* parent) {
    ++currheight_;
    if (root == nullptr) {
      auto node = new Node(key);
      node->parent = parent;
      return node;
    }
    if (root->key > key) {
      root->left = Push(key, root->left, root);
    }
    if (root->key < key) {
      root->right = Push(key, root->right, root);
    }
    return root;
  }

  Node* Max(Node* root) {
    if (root->right != nullptr) {
      return Max(root->right);
    }
    return root;
  }

 public:
  void Push(int64_t key) {
    if (height_ == 0) {
      root_ = Push(key, root_, nullptr);
      ++height_;
    } else {
      Push(key, root_, nullptr);
    }
    height_ = std::max(height_, currheight_);
    currheight_ = 0;
  }

  int64_t Height() {
    return height_;
  }

  void Execute() {
    Execute(root_);
  }

  int64_t Max() {
    return Max(root_)->key;
  }

  int64_t SecondMax() {
    Node* max = Max(root_);
    if (max->parent == nullptr) {
      return Max(max->left)->key;
    }
    if (max->left == nullptr) {
      return max->parent->key;
    }
    return std::max(max->parent->key, Max(max->left)->key);
  }
};

int main() {
  int key;
  BinSearchTree tree = BinSearchTree();
  do {
    std::cin >> key;
    if (key != 0) {
      tree.Push(key);
    }
  } while (key != 0);
  std::cout << tree.SecondMax();
  tree.Execute();
}