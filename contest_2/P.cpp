#include <iostream>

struct Node {
  const int64_t key;
  Node* left = nullptr;
  Node* right = nullptr;
  int height = 1;

  explicit Node(const int64_t key) : key(key) {
  }
};

class AVL {
  Node* root_ = nullptr;
  size_t Height(Node* node) {
    return node == nullptr ? 0 : node->height;
  }

  int BF(Node* node) {
    if (node == nullptr) {
      return 0;
    }
    return Height(node->right) - Height(node->left);
  }

  void FixHeight(Node* node) {
    if (node == nullptr) {
      return;
    }
    node->height = std::max(Height(node->left), Height(node->right)) + 1;
  }

  Node* RR(Node* root) {
    Node* new_root = root->left;
    if (root == root_) {
      root_ = new_root;
    }
    root->left = new_root->right;
    new_root->right = root;

    FixHeight(root);
    FixHeight(new_root);
    return new_root;
  }

  Node* LR(Node* root) {
    Node* new_root = root->right;
    if (root == root_) {
      root_ = new_root;
    }
    root->right = new_root->left;
    new_root->left = root;

    FixHeight(root);
    FixHeight(new_root);
    return new_root;
  }

  Node* Balance(Node* node) {
    FixHeight(node);
    if (BF(node) == 2) {
      if (BF(node->right) == -1) {
        node->right = RR(node->right);
      }
      return LR(node);
    }
    if (BF(node) == -2) {
      if (BF(node->left) == 1) {
        node->left = LR(node->left);
      }
      return RR(node);
    }
    return node;
  }

  Node* Insert(Node* node, int64_t key) {
    if (Height(root_) == 0) {
      root_ = new Node(key);
      return nullptr;
    }

    if (node == nullptr) {
      auto new_node = new Node(key);
      return new_node;
    }
    if (key < node->key) {
      node->left = Insert(node->left, key);
    } else {
      if (key > node->key) {
        node->right = Insert(node->right, key);
      }
    }
    return Balance(node);
  }

  int64_t Next(Node* root, int64_t key) {
    if (root == nullptr) {
      return -1;
    }
    if (root->key < key) {
      return Next(root->right, key);
    }
    if (root->key > key) {
      if (root->left == nullptr || Next(root->left, key) == -1) {
        return root->key;
      }
      return Next(root->left, key);
    }
    return root->key;
  }

  void Clear(Node* node) {
    if (node == nullptr) {
      return;
    }
    Clear(node->left);
    Clear(node->right);
    delete node;
  }

 public:
  void Insert(int64_t key) {
    Insert(root_, key);
  }

  int64_t Next(int64_t key) {
    return Next(root_, key);
  }

  void Clear() {
    Clear(root_);
  }
};

int main() {
  int n;
  std::cin >> n;
  AVL tree = AVL();
  char cmd;
  int64_t key;
  int64_t lastkey = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> cmd >> key;
    if (cmd == '+') {
      tree.Insert((key + lastkey) % 1'000'000'000);
      lastkey = 0;
    } else {
      std::cout << tree.Next(key) << ' ';
      lastkey = tree.Next(key);
    }
  }
  tree.Clear();
}