#include <cstring>
#include <iostream>

bool IsLetter(char letter) {
  return 'A' <= toupper(letter) && toupper(letter) <= 'Z';
}

bool Check(char *line) {
  int64_t len = std::strlen(line);
  for (int64_t i = 0; i < len; ++i) {
    if (line[i] != line[len - i - 1]) {
      return false;
    }
  }
  return true;
}

void Remove(char *line, int64_t x, char *rem) {
  int64_t len = std::strlen(line);
  int64_t m = 0;
  for (int64_t i = 0; i < len; ++i) {
    if (i != x) {
      rem[m] = line[i];
      m++;
    }
  }
}

void Replace(char *line, int64_t x, int64_t y, char *rep) {
  int64_t len = std::strlen(line);
  for (int64_t i = 0; i < len; ++i) {
    rep[i] = line[i];
  }
  rep[x] = line[y];
}

int main() {
  char testline[100000];
  int64_t len = 0;
  std::cin.getline(testline, 100000);
  int64_t testlen = std::strlen(testline);
  for (int64_t i = 0; i < testlen; ++i) {
    if (IsLetter(testline[i])) {
      len++;
    }
  }

  char line[100000];
  int64_t m = 0;
  for (int64_t i = 0; i < testlen; ++i) {
    if (IsLetter(testline[i])) {
      line[m] = toupper(testline[i]);
      m++;
    }
  }

  int64_t x;
  int64_t y;
  for (int64_t i = 0; i < len; ++i) {
    if (line[i] != line[len - i - 1]) {
      x = i;
      y = len - i - 1;
      break;
    }
  }

  if (Check(line)) {
    std::cout << "YES" << std::endl << line;
  } else {
    char a[100000];
    Remove(line, x, a);
    if (Check(a)) {
      std::cout << "YES" << std::endl << a;
    } else {
      char a[100000];
      Remove(line, y, a);
      if (Check(a)) {
        std::cout << "YES" << std::endl << a;
      } else {
        char a[100000];
        Replace(line, x, y, a);
        if (Check(a)) {
          std::cout << "YES" << std::endl << a;
        } else {
          std::cout << "NO";
        }
      }
    }
  }
}