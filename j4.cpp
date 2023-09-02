#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll int64_t

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  unordered_map<string, unordered_set<string>> cannot;
  unordered_map<string, vector<string>> must;

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string p1, p2;
    cin >> p1 >> p2;
    must[p1].push_back(p2);
    must[p2].push_back(p1);
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    string p1, p2;
    cin >> p1 >> p2;
    cannot[p1].insert(p2);
    cannot[p2].insert(p1);
  }
  int ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    if (cannot[p1].count(p2)) {
      ans++;
    }
    if (cannot[p1].count(p3)) {
      ans++;
    }
    if (cannot[p2].count(p1)) {
      ans++;
    }
    if (cannot[p2].count(p3)) {
      ans++;
    }
    if (cannot[p3].count(p1)) {
      ans++;
    }
    if (cannot[p3].count(p2)) {
      ans++;
    }
    for (auto &m1 : must[p1]) {
      if (m1 != p3 && m1 != p2) {
        ans++;
      }
    }
    for (auto &m2 : must[p2]) {
      if (m2 != p3 && m2 != p1) {
        ans++;
      }
    }
    for (auto &m3 : must[p3]) {
      if (m3 != p1 && m3 != p2) {
        ans++;
      }
    }
  }

  cout << ans / 2 << "\n";

  return 0;
}
