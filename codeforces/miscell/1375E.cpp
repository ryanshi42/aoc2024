#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <numeric>
 
 
using namespace std;
 
 
 
int main() {
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(n);
  std::iota(b.begin(), b.end(), 0);
  std::sort(b.begin(), b.end(), [&](int i, int j) {
    if (a[i] != a[j]) {
      return a[i] < a[j];
    }
    return i < j;
  });
  vector<pair<int, int>> ret;
  for (int it = 0; it < n; it++) {
    for (int i = 0; i < n - 1; i++) {
      if (b[i] > b[i + 1]) {
        ret.emplace_back(b[i + 1], b[i]);
        swap(b[i], b[i + 1]);
      }
    }
  }
  cout << ret.size() << '\n';
  for (auto& p : ret) {
    cout << p.first + 1 << " " << p.second + 1 << '\n';
  }
  return 0;
}