#include <cstring>
#include <iostream>

struct Node {
  Node* up;
  Node* down;
  const int64_t key;

  explicit Node(int64_t key) : up(nullptr), down(nullptr), key(key) {
  }
};

class Deque {
 private:
  Node* bottom_;
  Node* top_;
  int64_t size_;

 public:
  Deque() : bottom_(nullptr), top_(nullptr), size_(0) {
  }

  void PushBack(int64_t key) {
    auto new_node = new Node(key);
    if (size_ == 0) {
      bottom_ = new_node;
      top_ = new_node;
      ++size_;
    } else {
      new_node->down = top_;
      top_->up = new_node;
      top_ = new_node;
      ++size_;
    }
  }

  void PushFront(int64_t key) {
    auto new_node = new Node(key);
    if (size_ == 0) {
      bottom_ = new_node;
      top_ = new_node;
      ++size_;
    } else {
      bottom_->down = new_node;
      new_node->up = bottom_;
      bottom_ = new_node;
      ++size_;
    }
  }

  int64_t PopFront() {
    int64_t key = bottom_->key;
    --size_;
    if (size_ == 0) {
      delete bottom_;
      bottom_ = nullptr;
      top_ = nullptr;
    } else {
      bottom_ = bottom_->up;
      delete bottom_->down;
    }
    return key;
  }

  int64_t PopBack() {
    int64_t key = top_->key;
    --size_;
    if (size_ == 0) {
      delete top_;
      bottom_ = nullptr;
      top_ = nullptr;
    } else {
      top_ = top_->down;
      delete top_->up;
    }
    return key;
  }

  int64_t Front() {
    return bottom_->key;
  }

  int64_t Back() {
    return top_->key;
  }

  int64_t Size() {
    return size_;
  }

  void Clear() {
    while (size_ > 0) {
      PopBack();
    }
  }
};

class Queue {
 private:
  Node* bottom_;
  Node* top_;
  int64_t size_;

 public:
  Queue() : bottom_(nullptr), top_(nullptr), size_(0) {
  }

  void Push(int64_t key) {
    auto new_node = new Node(key);
    if (size_ == 0) {
      bottom_ = new_node;
      top_ = new_node;
      ++size_;
    } else {
      new_node->down = top_;
      top_->up = new_node;
      top_ = new_node;
      ++size_;
    }
  }

  int64_t Pop() {
    int64_t key = bottom_->key;
    --size_;
    if (size_ == 0) {
      delete top_;
      bottom_ = nullptr;
      top_ = nullptr;
    } else {
      bottom_ = bottom_->up;
      delete bottom_->down;
    }
    return key;
  }

  int64_t Front() {
    return bottom_->key;
  }

  int64_t Back() {
    return top_->key;
  }

  int64_t Size() {
    return size_;
  }

  void Clear() {
    while (size_ > 0) {
      Pop();
    }
  }
};

class MinQueue {
 private:
  Queue que_;
  Deque min_;

 public:
  MinQueue() : que_(Queue()), min_(Deque()) {
  }

  void Enqueue(int64_t key) {
    if (que_.Size() == 0) {
      que_.Push(key);
      min_.PushBack(key);
    } else {
      que_.Push(key);
      while (!min_.Size() == 0 && min_.Back() > key) {
        min_.PopBack();
      }
      min_.PushBack(key);
    }
  }

  int64_t Dequeue() {
    if (que_.Front() == min_.Front()) {
      que_.Pop();
      return min_.PopFront();
    }
    return que_.Pop();
  }

  int64_t GetMin() {
    return min_.Front();
  }

  void Clearminq() {
    min_.Clear();
    que_.Clear();
  }

  int64_t Front() {
    return que_.Front();
  }

  int64_t Size() {
    return que_.Size();
  }
};

int main() {
  int64_t n;
  std::cin >> n;
  char cmd[20];
  MinQueue minq = MinQueue();
  int64_t key;
  for (int64_t i = 0; i < n; ++i) {
    std::cin >> cmd;
    switch (cmd[0]) {
      case ('e'):
        std::cin >> key;
        minq.Enqueue(key);
        std::cout << "ok" << '\n';
        break;

      case ('d'):
        if (minq.Size() != 0) {
          std::cout << minq.Dequeue() << '\n';
        } else {
          std::cout << "error" << '\n';
        }
        break;

      case ('f'):
        if (minq.Size() != 0) {
          std::cout << minq.Front() << '\n';
        } else {
          std::cout << "error" << '\n';
        }
        break;

      case ('s'):
        std::cout << minq.Size() << '\n';
        break;

      case ('c'):
        minq.Clearminq();
        std::cout << "ok" << '\n';
        break;

      case ('m'):
        if (minq.Size() != 0) {
          std::cout << minq.GetMin() << '\n';
        } else {
          std::cout << "error" << '\n';
        }
        break;
    }
  }
  minq.Clearminq();
}