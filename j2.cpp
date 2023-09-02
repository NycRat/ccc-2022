#include <iostream>

#define ll int64_t

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, good = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int points, fouls;
    cin >> points >> fouls;

    if (points * 5 - fouls * 3 > 40) {
      good++;
    }
  }

  cout << good << (good == n ? "+" : "") << "\n";

  return 0;
}
