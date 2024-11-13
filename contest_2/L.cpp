#include <iostream>

struct Node {
  const int64_t key;
  Node* left = nullptr;
  Node* right = nullptr;

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

  Node* Push(int64_t key, Node* root) {
    ++currheight_;
    if (root == nullptr) {
      return new Node(key);
    }
    if (root->key > key) {
      root->left = Push(key, root->left);
    }
    if (root->key < key) {
      root->right = Push(key, root->right);
    }
    return root;
  }

 public:
  void Push(int64_t key) {
    if (height_ == 0) {
      root_ = Push(key, root_);
      ++height_;
    } else {
      Push(key, root_);
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
  std::cout << tree.Height();
  tree.Execute();
}