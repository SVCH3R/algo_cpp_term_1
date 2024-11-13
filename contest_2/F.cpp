#include <cstring>
#include <iostream>

struct Node {
  Node* left;
  Node* right;
  const int key;

  explicit Node(int key) : left(nullptr), right(nullptr), key(key) {
  }
};

class Deque {
 private:
  Node* first_;
  Node* last_;
  int size_;

 public:
  Deque() : first_(nullptr), last_(nullptr), size_(0) {
  }

  void PushBack(int key) {
    auto new_node = new Node(key);
    if (size_ == 0) {
      first_ = new_node;
      last_ = new_node;
      std::cout << "ok" << '\n';
      ++size_;
    } else {
      last_->right = new_node;
      new_node->left = last_;
      last_ = new_node;
      std::cout << "ok" << '\n';
      ++size_;
    }
  }

  void PushFront(int key) {
    auto new_node = new Node(key);
    if (size_ == 0) {
      first_ = new_node;
      last_ = new_node;
      ++size_;
      std::cout << "ok" << '\n';
    } else {
      first_->left = new_node;
      new_node->right = first_;
      first_ = new_node;
      std::cout << "ok" << '\n';
      ++size_;
    }
  }

  void PopFront() {
    if (size_ == 0) {
      std::cout << "error" << '\n';
    } else {
      std::cout << first_->key << '\n';
      --size_;
      if (size_ == 0) {
        delete first_;
        first_ = nullptr;
        last_ = nullptr;
      } else {
        first_ = first_->right;
        delete first_->left;
      }
    }
  }

  void PopBack() {
    if (size_ == 0) {
      std::cout << "error" << '\n';
    } else {
      std::cout << last_->key << '\n';
      --size_;
      if (size_ == 0) {
        delete last_;
        first_ = nullptr;
        last_ = nullptr;
      } else {
        last_ = last_->left;
        delete last_->right;
      }
    }
  }

  void FrontKey() {
    if (size_ == 0) {
      std::cout << "error" << '\n';
    } else {
      std::cout << first_->key << '\n';
    }
  }

  void BackKey() {
    if (size_ == 0) {
      std::cout << "error" << '\n';
    } else {
      std::cout << last_->key << '\n';
    }
  }

  void Size() {
    std::cout << size_ << '\n';
  }

  void Clear() {
    while (size_ > 2) {
      first_->right = first_->right->right;
      delete first_->right->left;
      first_->right->left = first_;
      --size_;
    }

    if (first_ == last_) {
      delete first_;
      --size_;
    } else {
      delete first_;
      delete last_;
    }
    size_ = 0;
    first_ = nullptr;
    last_ = nullptr;
  }
};

int main() {
  int n;
  std::cin >> n;
  char cmd[20];
  Deque q = Deque();
  int key;
  for (int i = 0; i < n; ++i) {
    std::cin >> cmd;
    if (std::strlen(cmd) > 7) {
      switch (cmd[5]) {
        case 'f': {
          std::cin >> key;
          q.PushFront(key);
          break;
        }
        case 'b': {
          std::cin >> key;
          q.PushBack(key);
          break;
        }
        case 'r': {
          q.PopFront();
          break;
        }
        case 'a': {
          q.PopBack();
          break;
        }
      }
    } else {
      switch (cmd[0]) {
        case 'f': {
          q.FrontKey();
          break;
        }
        case 'b': {
          q.BackKey();
          break;
        }
        case 's': {
          q.Size();
          break;
        }
        case 'c': {
          q.Clear();
          std::cout << "ok" << '\n';
          break;
        }
        case 'e': {
          q.Clear();
          std::cout << "bye" << '\n';
          return 0;
        }
      }
    }
  }
}