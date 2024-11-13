#include <cmath>
#include <iostream>

void Tri(int64_t dec, int64_t *comb, int64_t m) {
  for (int64_t i = 0; i < m; ++i) {
    comb[i] = 0;
  }
  for (int64_t i = 0; dec; ++i) {
    comb[i] = dec % 3;
    dec /= 3;
  }
}

int64_t Sum(int64_t *comb, int64_t *coins, int64_t m, int64_t &cnt) {
  int64_t ret = 0;
  cnt = 0;
  for (int64_t i = 0; i < m; ++i) {
    ret += coins[i] * comb[i];
    cnt += comb[i];
  }
  return ret;
}

int main() {
  int64_t n, m;
  std::cin >> n;
  std::cin >> m;
  int64_t summ = 0;
  auto coins = new int64_t[m];
  for (int64_t i = 0; i < m; ++i) {
    std::cin >> coins[i];
    if (coins[i] > n) {
      --i;
      --m;
    }
    summ += coins[i] * 2;
  }
  auto comb = new int64_t[m];
  for (int64_t i = 0; i < m; ++i) {
    comb[i] = 0;
  }

  int64_t numcomb = pow(3, m);
  int64_t cnt = 0;

  if (summ < n) {
    std::cout << -1;
    delete[] coins;
    delete[] comb;
    return 0;
  }

  int64_t mincoins = 31;
  int64_t mincomb = -1;

  for (int64_t i = 0; i < numcomb; ++i) {
    Tri(i, comb, m);
    if (Sum(comb, coins, m, cnt) == n && cnt < mincoins) {
      mincoins = cnt;
      mincomb = i;
    }
  }

  if (mincoins == 31) {
    std::cout << 0;
  } else {
    Tri(mincomb, comb, m);
    std::cout << mincoins << std::endl;
    for (int64_t i = 0; i < m; ++i) {
      if (comb[i] == 2) {
        std::cout << coins[i] << ' ' << coins[i] << ' ';
      }
      if (comb[i] == 1) {
        std::cout << coins[i] << ' ';
      }
    }
  }
  delete[] coins;
  delete[] comb;
}