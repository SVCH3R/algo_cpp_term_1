#include <cstring>
#include <iostream>

struct Node {
  Node* left;
  Node* right;
  const char key;

  explicit Node(char key) : left(nullptr), right(nullptr), key(key) {
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
      ++size_;
    } else {
      last_->right = new_node;
      new_node->left = last_;
      last_ = new_node;
      ++size_;
    }
  }

  char Back() {
    return last_->key;
  }

  char PopBack() {
    char key = last_->key;
    --size_;
    if (size_ == 0) {
      delete last_;
      first_ = nullptr;
      last_ = nullptr;
    } else {
      last_ = last_->left;
      delete last_->right;
    }
    return key;
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

  int64_t Size() {
    return size_;
  }
};

int main() {
  char line[1000000];
  std::cin.getline(line, 1000000);
  Deque stack = Deque();
  size_t len = std::strlen(line);
  for (size_t i = 0; i < len; ++i) {
    if (stack.Size() == 0) {
      stack.PushBack(line[i]);
    } else {
      if ((stack.Back() == '(' && line[i] == ')') || (stack.Back() == '{' && line[i] == '}') ||
          (stack.Back() == '[' && line[i] == ']')) {
        stack.PopBack();
      } else {
        stack.PushBack(line[i]);
      }
    }
  }
  if (stack.Size() == 0) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
  stack.Clear();
}
